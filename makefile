programa: peleaController mainController posController tomarController arma ataque entidad item jefe jugador mazmorra pocionAtaque pocionEscape pocionMuerte pocionResistencia pocionVida villano
	g++ -o Juego fightcontroller.o maincontroller.o poscontroller.o takecontroller.o Arma.o ataque.o entidad.o Item.o jefe.o jugador.o mazmorra.o PocionAtaque.o PocionEscape.o PocionMuerte.o PocionResistencia.o PocionVida.o villano.o
peleaController: controller/fightcontroller.cpp controller/fightcontroller.h
	g++ -c controller/fightcontroller.cpp
mainController: controller/maincontroller.cpp controller/maincontroller.h
	g++ -c controller/maincontroller.cpp
posController: controller/poscontroller.cpp controller/poscontroller.h
	g++ -c controller/poscontroller.cpp
tomarController: controller/takecontroller.cpp controller/takecontroller.h
	g++ -c controller/takecontroller.cpp
arma: model/Arma.cpp model/Arma.h
	g++ -c model/Arma.cpp
ataque: model/ataque.cpp model/ataque.h
	g+ -c model/ataque.cpp
entidad: model/entidad.cpp model/entidad.h
	g+ -c model/entidad.cpp
item: model/Item.cpp model/Item.h
	g+ -c model/Item.cpp
jefe: model/jefe.cpp model/jefe.h
	g+ -c model/jefe.cpp
jugador: model/jugador.cpp model/jugador.h
	g+ -c model/jugador.cpp
mazmorra: model/mazmorra.cpp model/mazmorra.h
	g+ -c model/mazmorra.cpp
pocionAtaque: model/PocionAtaque.cpp model/PocionAtaque.h
	g+ -c model/PocionAtaque.cpp
pocionEscape: model/PocionEscape.cpp model/PocionEscape.h
	g+ -c model/PocionEscape.cpp
pocionMuerte: model/PocionMuerte.cpp model/PocionMuerte.h
	g+ -c model/PocionMuerte.cpp
pocionResistencia: model/PocionResistencia.cpp model/PocionResistencia.h
	g+ -c model/PocionResistencia.cpp
pocionVida: model/PocionVida.cpp model/PocionVida.h
	g+ -c model/PocionVida.cpp
villano: model/villano.cpp model/villano.h
	g+ -c model/villano.cpp

clean: #comando para borrar los .o
	del *.o, del *.exe
