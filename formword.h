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

#ifndef FORMWORD_H
#define FORMWORD_H

#include <random>
#include <ctime>

#include <QMessageBox>
#include <QRegularExpression>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class FormWord; }
QT_END_NAMESPACE

class FormWord : public QMainWindow
{
    Q_OBJECT

public:
    FormWord(QWidget *parent = nullptr);
    ~FormWord();

private slots:
    void on_Formation_clicked();

private:
    Ui::FormWord *ui;
    QString Word;
    int Capacity, randInt, key;
    QChar replacement;
};
#endif // FORMWORD_H
