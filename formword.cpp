/* ****************************************************************************
 * -------------------------------------------------------------------------- *
 *                                                                            *
 * Copyright © 2021 Kalynovsky Valentin. All rights reserved.                 *
 * Licensed under the Apache License, Version 2.0                             *
 *                                                                            *
 * Licensed under the Apache License, Version 2.0 (the "License");            *
 * you may not use this file except in compliance with the License.           *
 * You may obtain a copy of the License at                                    *
 *                                                                            *
 *     http://www.apache.org/licenses/LICENSE-2.0                             *
 *                                                                            *
 * Unless required by applicable law or agreed to in writing, software        *
 * distributed under the License is distributed on an "AS IS" BASIS,          *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   *
 * See the License for the specific language governing permissions and        *
 * limitations under the License.                                             *
 *                                                                            *
 * -------------------------------------------------------------------------- *
 * ************************************************************************** */

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
