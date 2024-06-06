#include <QApplication>
#include "core/app.h"

int main(int aNumArgs, char *aArgArray[])
{
	QApplication kuApp(aNumArgs, aArgArray);

	App::sInstance();
	return kuApp.exec();
}
