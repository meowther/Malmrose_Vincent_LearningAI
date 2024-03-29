#include <qtgui\qapplication.h>
#include <Rendering\Renderer.h>
#include <IO\FileIO.h>
#include <Rendering\Helpers\Renderables.h>
#include <MyGame.h>
#include "Asteroids\AsterMain.h"
#include "Other_Tests\RBM.h"
#include <iostream>
#include "AI\DeepLearner.h"

bool Testing_Others = false;
bool Test_Asteroids = false;
bool cont = true;
//Bla

int main(int argumentCount, char* argumentVector[]){
	if (Testing_Others){
		//Not actually helpful, unless I call the functions myself
		RBM* rbm = new RBM(0, 0, 0, NULL, NULL, NULL);
		//Seems to print an array that resembles the test data
		rbm->test_rbm();
		delete rbm;
	}
	else if (Test_Asteroids){
		AsterMain newGame;
		newGame.run();
	}
	
	else{
		QApplication app(argumentCount, argumentVector);

		MyGame game;
		DeepLearner AI;
		game.setAI(&AI);
		while (cont){
			if (!game.initialize(&cont))
				return;

			game.gameLoop();
			game.AttachAI(&AI);

			app.exec();
			AI.ResetScore();

			game.shutdown();
			app.closeAllWindows();
			app.exit();
			app.quit();
		}
	};

	return 0;
}