#include <QApplication>
#include "core/app.h"

int main(int aNumArgs, char *aArgArray[])
{
	Q_INIT_RESOURCE(Tetris);

	QApplication kuApp(aNumArgs, aArgArray);

	App::sInstance();
	return kuApp.exec();
}
