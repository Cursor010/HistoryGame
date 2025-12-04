#include "mainwindow.h"

#include <QCloseEvent>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QTimer>
#include <QVBoxLayout>

#include "gamewindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
    ui_(new Ui::MainWindow) {
    ui_->setupUi(this);

    // Сбрасываем сохраненные имена
    saved_player_names_.clear();

    // Устанавливаем значение по умолчанию для количества игроков
    ui_->playerCountSpinBox->setValue(2);

    SetupPlayersLayout();

    // Устанавливаем курсор после первого символа в QSpinBox
    QTimer::singleShot(0, this, [this]() {
        QLineEdit* spin_box_line_edit =
            ui_->playerCountSpinBox->findChild<QLineEdit*>();
        if (spin_box_line_edit) {
            spin_box_line_edit->setCursorPosition(1);
        }
    });
}

MainWindow::~MainWindow() {
    delete ui_;
}

void MainWindow::ResetToDefault() {
    // Сбрасываем количество игроков к значению по умолчанию
    ui_->playerCountSpinBox->setValue(2);

    // Очищаем сохраненные имена
    saved_player_names_.clear();

    // Принудительно обновляем layout
    SetupPlayersLayout();
}

void MainWindow::SetupPlayersLayout() {
    // Сохраняем текущие имена игроков перед очисткой
    QStringList current_names;
    for (QLineEdit* input : player_inputs_) {
        QString name = input->text().trimmed();
        if (name.isEmpty() || name.startsWith("Игрок ")) {
            current_names.append("");  // Пустое имя для дефолтных значений
        } else {
            current_names.append(name);
        }
    }

    // Сохраняем имена, но только если у нас уже есть сохраненные имена
    // или мы в процессе первого запуска
    if (saved_player_names_.isEmpty() || !current_names.isEmpty()) {
        saved_player_names_ = current_names;
    }

    // Очищаем старые поля ввода и layouts
    for (QLineEdit* input : player_inputs_) {
        input->deleteLater();
    }
    player_inputs_.clear();

    for (QHBoxLayout* layout : player_layouts_) {
        // Удаляем все виджеты из layout
        QLayoutItem* item;
        while ((item = layout->takeAt(0)) != nullptr) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }
        delete layout;
    }
    player_layouts_.clear();

    int player_count = ui_->playerCountSpinBox->value();

    for (int i = 0; i < player_count; ++i) {
        QHBoxLayout* player_layout = new QHBoxLayout();
        player_layout->setSpacing(15);

        // Создаем контейнер для номера игрока
        QFrame* number_frame = new QFrame();
        number_frame->setFixedSize(40, 40);
        number_frame->setStyleSheet(R"(
      QFrame {
        background-color: #3498db;
        border-radius: 5px;
        border: 2px solid #2980b9;
      }
    )");

        QLabel* number_label = new QLabel(QString::number(i + 1));
        number_label->setAlignment(Qt::AlignCenter);
        number_label->setStyleSheet(R"(
      QLabel {
        color: white;
        font-size: 16px;
        font-weight: bold;
        background: transparent;
      }
    )");

        QVBoxLayout* number_layout = new QVBoxLayout(number_frame);
        number_layout->addWidget(number_label);
        number_layout->setContentsMargins(0, 0, 0, 0);

        // Проверяем, есть ли сохраненное имя для этого индекса
        QString default_name;
        if (i < saved_player_names_.size() && !saved_player_names_[i].isEmpty()) {
            // Используем сохраненное имя
            default_name = saved_player_names_[i];
        } else {
            // Используем имя по умолчанию
            default_name = QString("Игрок %1").arg(i + 1);
        }

        // Поле ввода для имени игрока
        QLineEdit* player_input = new QLineEdit(default_name);
        player_input->setStyleSheet(R"(
      QLineEdit {
        border: 2px solid #7f8c8d;
        border-radius: 8px;
        padding: 10px;
        font-size: 14px;
        background-color: #2c3e50;
        color: #ecf0f1;
        selection-background-color: #3498db;
        selection-color: white;
      }
      QLineEdit:focus {
        border-color: #3498db;
        background-color: #34495e;
      }
      QLineEdit:hover {
        border-color: #95a5a6;
      }
      QLineEdit:disabled {
        background-color: #4a6278;
        color: #bdc3c7;
      }
    )");
        player_input->setMinimumHeight(40);

        // Устанавливаем курсор после первого символа
        QTimer::singleShot(0, [player_input]() {
            QString text = player_input->text();
            if (!text.isEmpty()) {
                player_input->setCursorPosition(1);
            }
        });

        // Добавляем элементы в layout
        player_layout->addWidget(number_frame);
        player_layout->addWidget(player_input, 1);  // 1 означает растягивание

        // Добавляем layout в основной
        ui_->playersLayout->insertLayout(ui_->playersLayout->count() - 1,
                                         player_layout);

        player_inputs_.append(player_input);
        player_layouts_.append(player_layout);
    }
}

void MainWindow::on_playerCountSpinBox_valueChanged(int arg1) {
    // Сохраняем текущие имена перед обновлением
    saved_player_names_.clear();
    for (QLineEdit* input : player_inputs_) {
        QString name = input->text().trimmed();
        saved_player_names_.append(name);
    }

    SetupPlayersLayout();
}

void MainWindow::closeEvent(QCloseEvent* event) {
    // Закрываем приложение при закрытии главного окна
    qApp->quit();
    event->accept();
}

void MainWindow::on_startGameButton_clicked() {
    QStringList player_names;
    for (QLineEdit* input : player_inputs_) {
        QString name = input->text().trimmed();
        if (!name.isEmpty()) {
            player_names.append(name);
        } else {
            player_names.append("Игрок");
        }
    }

    if (player_names.isEmpty()) {
        player_names.append("Игрок 1");
    }

    GameWindow* game_window = new GameWindow(player_names);
    game_window->show();
    this->hide();  // Используем hide() вместо close()
}
