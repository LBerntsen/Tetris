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
class Block;

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

public slots:
	void gameOverReciever();
	int keyTestReciever();

private:
	static App *sThis;
	MainWindow *mMainWindow;
	Game *mGame;
	Block *mBlock;
	GameScene *mScene;
};


#endif
