// GuessMyWord.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <string>
#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    bool play = true;
    bool wrongEnter = false;
    bool wordFind = true;
    bool charFind = true;
    string tabWords[10] = { "ciel", "maison", "port", "tortue", "eclipse", "lion", "rouge", "vitesse", "poisson", "language" };
    string wordToGuess = "ciel";
    string alphabet_min = "abcdefghijklmnopqrstuvwxyz";
    char userCharEnter;

    while (play)
    {
        //initialisation

        //ajouter le choix du nombre de lettre du mot à deviner

        srand(time(NULL));
        int randomNumber = rand() % tabWords->length();
        wordToGuess = tabWords[randomNumber];
        string wordCurrent = wordToGuess;
        wordCurrent.assign(wordCurrent.length(), '_');
        wordFind = true;
        charFind = true;

        while (wordFind)
        {

            cout << "MOT A DEVINER  " << wordCurrent <<endl << endl;

            //indique que la valeur saisie correspond à la valeur attendue
            wrongEnter = false;

            do
            {
                if (wrongEnter)
                {
                    cout << "Vous n'avez pas saisie une lettre" << endl << endl;
                }

                cout << "Saisir une lettre a - z" << endl;
                cin >> userCharEnter;

                wrongEnter = true;

            } while (alphabet_min.find(userCharEnter) == std::string::npos);
            
            //vérifier si la lettre entrée est dans le mot mystère


            //boucle tant que je trouve une valeur je continue de tourner
            int charFindIndex = 0;
            do
            {
                charFindIndex = wordToGuess.find(userCharEnter, charFindIndex);

                if (charFindIndex != std::string::npos)
                {
                    //préparer le mot en court, de la meme taille que le mot à trouver
                    wordCurrent[charFindIndex] = wordToGuess[charFindIndex];
                    charFindIndex++;
                }
                else
                {
                    charFind = false;
                }

            } while (charFind);



            //if (wordToGuess.find(userCharEnter) != std::string::npos)
        }

        // fin de partie
        // demande à l'utilisateur de recommencer une nouvelle partie ou non
        wrongEnter = false;
        do
        {
            if (wrongEnter)
            {
                cout << "Vous n'avez pas saisie o ou n" << endl << endl;
                cout << "Entrer 'o' pour recommencer ou 'n' pour arreter" << endl;
            }
            else
            {
                cout << "Une nouvelle partie ? o - n" << endl;
                wrongEnter = true;
            }
            cin >> userCharEnter;

        } while ( (userCharEnter != 'o') || (userCharEnter != 'n') );

        if (userCharEnter == 'o')
        {
            cout << "OK. Bonne chance pour cette nouvelle partie" << endl;

        }
        else
        {
            cout << ":( c'est votre choix. AU REVOIR" << endl;
            play = false;
        }

    }//Fin de partie

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
