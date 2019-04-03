#ifndef APP_H
#define APP_H

// QT header files
#include <QObject>

// Forward declarations
class QMessageBox;
class QGraphicsScene;
class QGraphicsTextItem;
class MainWindow;
class Game;

enum TileType { eInvalid = -1, eGreen, eGray };

/** Singleton MountainDew Valley; application class.
*/
class App : public QObject
{
	Q_OBJECT

	App();
public:
	virtual ~App();

	static App *sInstance();
	MainWindow *getMainWindow() const;
	QGraphicsScene *getScene() const;
	void startGameMenu();

private:
	static App *sThis;
	MainWindow *mMainWindow;
	Game *mGame;
};


#endif
