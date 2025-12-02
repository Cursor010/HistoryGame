#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QDialog>

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ResultsWindow(const QStringList &players, const QVector<int> &scores, QWidget *parent = nullptr);
    ~ResultsWindow();

signals:
    void returnToMainMenu();  // Добавьте этот сигнал

private slots:
    void on_closeButton_clicked();

private:
    Ui::ResultsWindow *ui;

    QVector<QPair<QString, int>> getSortedResults(const QStringList &players, const QVector<int> &scores) const;
    QString getPlaceText(int place) const;
    QString getPlaceStyle(int place) const;
    void setupResultsTable(const QVector<QPair<QString, int>> &sortedResults);
};

#endif // RESULTSWINDOW_H
