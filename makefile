programa: main.o view.o peleaController.o mainController.o posController.o tomarController.o arma.o ataque.o\
		  entidad.o item.o jefe.o jugador.o mazmorra.o pocionAtaque.o pocionEscape.o pocionMuerte.o\
		  pocionResistencia.o pocionVida.o villano.o
	g++ -o Juego main.o view.o fightcontroller.o maincontroller.o poscontroller.o takecontroller.o Arma.o\
		   ataque.o entidad.o Item.o jefe.o jugador.o mazmorra.o PocionAtaque.o PocionEscape.o PocionMuerte.o\
		   PocionResistencia.o PocionVida.o villano.o
main.o: main.cpp view/view.h
	g++ -c main.cpp
view.o: view/view.cpp view/view.h
	g++ -c view/view.cpp
peleaController.o: controller/fightcontroller.cpp controller/fightcontroller.h
	g++ -c controller/fightcontroller.cpp
mainController.o: controller/maincontroller.cpp controller/maincontroller.h
	g++ -c controller/maincontroller.cpp
posController.o: controller/poscontroller.cpp controller/poscontroller.h
	g++ -c controller/poscontroller.cpp
tomarController.o: controller/takecontroller.cpp controller/takecontroller.h
	g++ -c controller/takecontroller.cpp
arma.o: model/Arma.cpp model/Arma.h
	g++ -c model/Arma.cpp
ataque.o: model/ataque.cpp model/ataque.h
	g++ -c model/ataque.cpp
entidad.o: model/entidad.cpp model/entidad.h
	g++ -c model/entidad.cpp
item.o: model/Item.cpp model/Item.h
	g++ -c model/Item.cpp
jefe.o: model/jefe.cpp model/jefe.h
	g++ -c model/jefe.cpp
jugador.o: model/jugador.cpp model/jugador.h
	g++ -c model/jugador.cpp
mazmorra.o: model/mazmorra.cpp model/mazmorra.h
	g++ -c model/mazmorra.cpp
pocionAtaque.o: model/PocionAtaque.cpp model/PocionAtaque.h
	g++ -c model/PocionAtaque.cpp
pocionEscape.o: model/PocionEscape.cpp model/PocionEscape.h
	g++ -c model/PocionEscape.cpp
pocionMuerte.o: model/PocionMuerte.cpp model/PocionMuerte.h
	g++ -c model/PocionMuerte.cpp
pocionResistencia.o: model/PocionResistencia.cpp model/PocionResistencia.h
	g++ -c model/PocionResistencia.cpp
pocionVida.o: model/PocionVida.cpp model/PocionVida.h
	g++ -c model/PocionVida.cpp
villano.o: model/villano.cpp model/villano.h
	g++ -c model/villano.cpp

clean: #comando para borrar los .o
	del *.o