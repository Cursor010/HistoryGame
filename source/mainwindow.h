#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_playerCountSpinBox_valueChanged(int arg1);
    void on_startGameButton_clicked();

private:
    void ResetToDefault();
    void SetupPlayersLayout();

    Ui::MainWindow* ui_;
    QList<class QLineEdit*> player_inputs_;
    QList<class QHBoxLayout*> player_layouts_;
    QStringList saved_player_names_;  // Для сохранения введенных имен
};

#endif  // MAINWINDOW_H
