#include <QApplication>
#include <QPushButton>
#include "src/Parser.h"

int main(int argc, char *argv[]) {
//    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
//    return QApplication::exec();
    Parser pars;
	pars.testTrades();
	pars.showAllTrades();
	pars.createJson();

    return 0;
}
