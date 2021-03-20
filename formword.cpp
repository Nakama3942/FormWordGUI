#include "formword.h"
#include "ui_formword.h"

FormWord::FormWord(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FormWord)
{
    ui->setupUi(this);
    ui->OutputWord->setReadOnly(1);
}

FormWord::~FormWord()
{
    delete ui;
}

void FormWord::on_Formation_clicked()
{
    QRegularExpression Space("\\s");
    QRegularExpression Symbol("\\!|\\@|\\#|\\$|\\%|\\^|\\&|\\*|\\(|\\)|\\-|\\+|\\=|\\||\\№|\\;|\\:|\\?|\\[|\\]|\\{|\\}|\\'|\\\"|\\,|\\<|\\.|\\>|\\/|\\?");
    if (ui->InputWord->text().contains(Space) == true)
    {
        QMessageBox Space(QMessageBox::Critical,
                                                "Space",
                                                "Обнаружен пробел. Вы ввели не слово или ник, а фразу!",
                                                QMessageBox::Ok);
        Space.exec();
    }
    else if (ui->InputWord->text().contains(Symbol) == true)
    {
        QMessageBox Symbol(QMessageBox::Critical,
                                                  "Symbol",
                                                  "Обнаружен символ. В слове или нике не может быть символа!",
                                                  QMessageBox::Ok);
        Symbol.exec();
    }
    else
    {
        Word = ui->InputWord->text();
        Capacity = Word.size();
        for (int i = 0; i < Capacity; i++)
        {
            srand(time(NULL));
            srand(i * rand());
            randInt = rand() % Capacity;
            replacement = Word[randInt];
            Word[randInt] = Word[i];
            Word[i] = replacement;
        }
        Word = Word.toLower();
        ui->OutputWord->setText(Word);
    }
}
