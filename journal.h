#ifndef JOURNAL_H
#define JOURNAL_H

#include <QDialog>

namespace Ui {
class Journal;
}

class Journal : public QDialog
{
    Q_OBJECT

public:
    explicit Journal(QWidget *parent = 0);


    ~Journal();

public slots:
    void print_to_journal(const QString &str);

private slots:
    void on_but_clear_journal_clicked();

private:
    Ui::Journal *ui;
};


#endif // JOURNAL_H
