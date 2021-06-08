programa: main.o view.o peleaController.o mainController.o posController.o tomarController.o arma.o ataque.o\
		  entidad.o item.o jefe.o jugador.o mazmorra.o pocionAtaque.o pocionEscape.o pocionMuerte.o\
		  pocionResistencia.o pocionVida.o villano.o
	g++ -std=c++14 -o Juego main.o view.o fightcontroller.o maincontroller.o poscontroller.o takecontroller.o Arma.o\
		   ataque.o entidad.o Item.o jefe.o jugador.o mazmorra.o PocionAtaque.o PocionEscape.o PocionMuerte.o\
		   PocionResistencia.o PocionVida.o villano.o
main.o: main.cpp view/view.h
	g++ -std=c++14  -c main.cpp
view.o: view/view.cpp view/view.h
	g++ -std=c++14 -c view/view.cpp
peleaController.o: controller/fightcontroller.cpp controller/fightcontroller.h
	g++ -std=c++14 -c controller/fightcontroller.cpp
mainController.o: controller/maincontroller.cpp controller/maincontroller.h
	g++ -std=c++14 -c controller/maincontroller.cpp
posController.o: controller/poscontroller.cpp controller/poscontroller.h
	g++ -std=c++14 -c controller/poscontroller.cpp
tomarController.o: controller/takecontroller.cpp controller/takecontroller.h
	g++ -std=c++14 -c controller/takecontroller.cpp
arma.o: model/Arma.cpp model/Arma.h
	g++ -std=c++14 -c model/Arma.cpp
ataque.o: model/ataque.cpp model/ataque.h
	g++ -std=c++14 -c model/ataque.cpp
entidad.o: model/entidad.cpp model/entidad.h
	g++ -std=c++14 -c model/entidad.cpp
item.o: model/Item.cpp model/Item.h
	g++ -std=c++14 -c model/Item.cpp
jefe.o: model/jefe.cpp model/jefe.h
	g++ -std=c++14 -c model/jefe.cpp
jugador.o: model/jugador.cpp model/jugador.h
	g++ -std=c++14 -c model/jugador.cpp
mazmorra.o: model/mazmorra.cpp model/mazmorra.h
	g++ -std=c++14 -c model/mazmorra.cpp
pocionAtaque.o: model/PocionAtaque.cpp model/PocionAtaque.h
	g++ -std=c++14 -c model/PocionAtaque.cpp
pocionEscape.o: model/PocionEscape.cpp model/PocionEscape.h
	g++ -std=c++14 -c model/PocionEscape.cpp
pocionMuerte.o: model/PocionMuerte.cpp model/PocionMuerte.h
	g++ -std=c++14 -c model/PocionMuerte.cpp
pocionResistencia.o: model/PocionResistencia.cpp model/PocionResistencia.h
	g++ -std=c++14 -c model/PocionResistencia.cpp
pocionVida.o: model/PocionVida.cpp model/PocionVida.h
	g++ -std=c++14 -c model/PocionVida.cpp
villano.o: model/villano.cpp model/villano.h
	g++ -std=c++14 -c model/villano.cpp

clean: #comando para borrar los .o
	rm -f *.o Juego