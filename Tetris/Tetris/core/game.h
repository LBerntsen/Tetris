#ifndef GAME_H 
#define GAME_H

#include <QObject>
#include <QString>
#include <QSize>

class GameScene;

class Game : public QObject
{
	Q_OBJECT

public:
	Game();
	virtual ~Game();
	GameScene *getScene();
	QSize getMapSize() const;
	void makeGrid(int aTileSize, int aRow, int aCols);
	void gameStart();

private:
	GameScene *mScene;
	QSize mSize;

private slots:
	void keyLeftReciever();
	void keyRightReciever();

};

#endif
