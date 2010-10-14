#Utilisation des librairies externes pré-compilées
#Il est recommandé de désactiver cette option et d'utiliser les librairies présente sur votre machine
#Par défaut cette option est activée pour une utilisation facile, sans avoir à installer toutes les dépendances
export USE_EXTLIBS= YES
#Compilateur utilisé g++
export CC=g++
#Flags pour le compilateur, -Wall pour activer tous les warnings
export CFLAGS=-Wall
#Dossier ou sera installer la librairie
export INST_PATH=$(PWD)/lib
#Dossiers où sont les headers nécessaires
export INC_PATH=-I $(PWD)/include -I $(PWD)/SFML/include
#Dossiers où sont les librairies nécessaires
export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML
#Ajout des dossiers des librairies nécessaires pour la SFML (avec ou sans utilisation du dossier extlibs suivant
#configuration de USE_EXTLIBS
ifeq ($(USE_EXTLIBS),YES)
	export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML -L $(PWD)/extlibs
else
	export LIB_PATH=-L $(INST_PATH) -L $(PWD)/lib/SFML
endif

#Compilation de la librairie
lib/libGefMoteur.a:
	@(git submodule init)
	@(git submodule update)
	@(cd src && $(MAKE))

#Installation de la librairie
install: lib/libGefMoteur.a
	@(cp lib/*.a /usr/lib/)
	@(cp -R include/* /usr/include/)

#Désinstallation de la librairie
uninstall:
	@(rm -f /usr/lib/libGefMoteur.a)
	@(rm -f -R /usr/include/GefMoteur)

#Compilation de la SFML
_SFML:
	@(git submodule init)
	@(git submodule update)
	@(mkdir -p ./lib/SFML/)
	-@(echo ".gitignore" > ./SFML/.gitignore)
	-@(echo "*.o" >> ./SFML/.gitignore)
	-@(patch -p0 -N -i ./SFML.patch)
	@(cd SFML && $(MAKE))
	@(cd SFML && git checkout src/SFML/Makefile)

#Compilation de testsfml
testsfml:lib/libGefMoteur.a _SFML
	@(cd test/testsfml && $(MAKE))

#exécution de testsfml
runtestsfml: testsfml
	@(cd test/testsfml && ./test)

#compilation de testsystem
testsystem:lib/libGefMoteur.a _SFML
	@(cd test/testsystem && $(MAKE))

#exécution de testsystem
runtestsystem:testsystem
	@(cd test/testsystem && ./test)

#nettoyage
clean:
	@(cd src && $(MAKE) clean)
	@(cd test/testsfml && $(MAKE) clean)
	@(cd test/testsystem && $(MAKE) clean)
	@(cd SFML && $(MAKE) clean)

#nettoyage complet
mrproper: clean
	@(cd lib && $(MAKE) mrproper)
	@(cd test/testsfml && $(MAKE) mrproper)
	@(cd test/testsystem && $(MAKE) mrproper)
	@(cd SFML && $(MAKE) mrproper)
