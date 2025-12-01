#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_playerCountSpinBox_valueChanged(int arg1);
    void on_startGameButton_clicked();

private:
    Ui::MainWindow *ui;
    void setupPlayersLayout();
    QList<class QLineEdit*> playerInputs;
    QList<class QHBoxLayout*> playerLayouts;
    QStringList savedPlayerNames; // Для сохранения введенных имен
};

#endif // MAINWINDOW_H
