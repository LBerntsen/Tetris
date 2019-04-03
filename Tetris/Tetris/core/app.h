#ifndef APP_H
#define APP_H

// QT header files
#include <QObject>

// Forward declarations
class GameScene;
class QMessageBox;
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
	GameScene *getScene() const;
	void startGameMenu();

private:
	static App *sThis;
	MainWindow *mMainWindow;
	Game *mGame;
};


#endif
