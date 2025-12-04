#ifndef RESULTSWINDOW_H
#define RESULTSWINDOW_H

#include <QDialog>
#include <QVector>
#include <QStringList>

namespace Ui {
class ResultsWindow;
}

class ResultsWindow : public QDialog {
    Q_OBJECT

public:
    explicit ResultsWindow(const QStringList& players,
                           const QVector<int>& scores,
                           QWidget* parent = nullptr);
    ~ResultsWindow();

signals:
    void returnToMainMenu();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void on_closeButton_clicked();

private:
    QVector<QPair<QString, int>> GetSortedResults(const QStringList& players,
                                                  const QVector<int>& scores) const;
    QString GetPlaceText(int place) const;
    QString GetPlaceStyle(int place) const;
    void SetupResultsTable(const QVector<QPair<QString, int>>& sorted_results);

    Ui::ResultsWindow* ui_;
};

#endif  // RESULTSWINDOW_H
