#ifndef MY_GAME
#define MY_GAME

#include <Qt\qobject.h>
#include <Qt\qtimer.h>
#include <QtGui\qmouseevent>
#include <Camera\Camera.h>
#include <Shapes\MyShapeData.h>
#include <Breakout\Ball.h>
#include <Breakout\Paddle.h>
#include <Breakout\Brick.h>

class PassInfo;
class Renderable;
class DebugMenu;
class QGroupBox;
class QVBoxLayout;
class Geometry;
class ShaderInfo;
class UniformInfo;
class TextureInfo;


class MyGame: public QObject{
	Q_OBJECT
		QTimer timer;

	void renderStuff();
	void updateCamera();
	void updateCameraFromMouse();
	void updateCameraFromKeyboard();

	PassInfo* pass;
	Camera camera;
	Renderable* lightRender;

	QWidget* window;
	QVBoxLayout* masterLayout;
	QWidget* debugWidget;
	QVBoxLayout* debugLayout;

	Geometry* brickGeo;
	Geometry* ballGeo;

	ShaderInfo* lightShader;
	ShaderInfo* dominateShader;

	UniformInfo* noUni;
	UniformInfo* tangentUniform;
	UniformInfo* dominateUniform;

	glm::vec3 camPos;
	glm::vec3 domColor;
	glm::vec3 light;
	
	static const int brickLineWidth = 8;
	static const int brickLineHeight = 4;
	Ball* ball;
	Brick* bricks[brickLineWidth][brickLineHeight];
	Paddle* paddle;
	bool isBreakout = false;
	bool isAsteroids = false;

	void generateGeometries();
	Renderable* makeBrick(glm::mat4 translate);
	Renderable* makeBall(glm::mat4 translate);

	void positionBricks();
	void positionBall();
	void positionPaddle();
	void Breakout();
	void Asteroids();

	private slots:
		void newFrame();

public:
	bool initialize();
	void gameLoop();
	bool shutdown();
	void rayTriangleIntersect(glm::vec3 rayOrigin, glm::vec3 ray_direciton, MyShapeData shape, float* minIntersection, glm::mat4 whereMat);

	MyGame() {}
};

#endif