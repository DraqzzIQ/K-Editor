// K-Editor
#include <QAddressArea>
#include <QCodeEditor>
#include <QSyntaxStyle>

// Qt
#include <QAbstractTextDocumentLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QScrollBar>
#include <QTextBlock>
#include <QTextEdit>

QAddressArea::QAddressArea(QCodeEditor* parent) : QWidget(parent), m_syntaxStyle(nullptr), m_codeEditParent(parent) {}

QSize QAddressArea::sizeHint() const
{
    if (m_codeEditParent == nullptr) {
        return QWidget::sizeHint();
    }

    // Calculating width
    // int digits = 1;
    // int max = qMax(1, m_codeEditParent->getInstructionSize());
    // while (max >= 16) {
    //     max /= 16;
    //     ++digits;
    // }
    int digits = 8;

#if QT_VERSION >= 0x050B00
    int space = 13 + m_codeEditParent->fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
#else
    int space = 13 + m_codeEditParent->fontMetrics().width(QLatin1Char('9')) * digits;
#endif

    return {space, 0};
}

void QAddressArea::setSyntaxStyle(QSyntaxStyle* style) { m_syntaxStyle = style; }

QSyntaxStyle* QAddressArea::syntaxStyle() const { return m_syntaxStyle; }

void QAddressArea::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);

    // Clearing rect to update
    painter.fillRect(event->rect(), m_syntaxStyle->getFormat("Text").background().color());

    auto blockNumber = m_codeEditParent->getFirstVisibleBlock();
    auto block = m_codeEditParent->document()->findBlockByNumber(blockNumber);
    auto top = static_cast<int>(m_codeEditParent->document()
                                    ->documentLayout()
                                    ->blockBoundingRect(block)
                                    .translated(0, -m_codeEditParent->verticalScrollBar()->value())
                                    .top());
    auto bottom =
        top + static_cast<int>(m_codeEditParent->document()->documentLayout()->blockBoundingRect(block).height());

    const auto otherLines = m_syntaxStyle->getFormat("LineNumber").foreground().color();

    painter.setFont(m_codeEditParent->font());

    while (block.isValid() && top <= event->rect().bottom()) {
        if (block.isVisible() && bottom >= event->rect().top()) {
            const int instruction = block.userState();
            QString number = instruction == -1 ? "" : QString("%1").arg(instruction, 8, 16, QChar('0'));

            painter.setPen(otherLines);

            painter.drawText(-5, top, sizeHint().width(), m_codeEditParent->fontMetrics().height(), Qt::AlignRight,
                             number);
        }

        block = block.next();
        top = bottom;
        bottom =
            top + static_cast<int>(m_codeEditParent->document()->documentLayout()->blockBoundingRect(block).height());
        ++blockNumber;
    }
}
