/*!
 * \file mainwindow.h
 * \brief Class MainWindow, g�re la fen�tre principale
 * \author Frederic Roge, Paul Villain
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QDialog>
#include <QUndoStack>
#include <QUndoCommand>
#include <QtGui>
#include <string>
#include <cctype>
#include <vector>
#include "logsystem.h"
#include "factoryconst.h"
#include "pile.h"
#include "calculateur.h"


namespace Ui {
    class MainWindow;
}

/*!
* \class MainWindow
* \brief Classe pour l'affichage de la calculatrice
*/
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
    * \brief Constructeur de MainWindow
    */
    explicit MainWindow(QWidget *parent = 0);
    /*!
    * \brief Destructeur de MainWindow
    */
    ~MainWindow();
    /*!
    * \brief Ajoute du texte � la MainWindow
    * \param chaine du message � ajouter
    */
    void ajouterTexte(const QString& s);
    /*!
    * \brief Efface du texte de la MainWindow
    */
    void effacerTexte();

signals:
    /*!
    * \brief Annule l'action effectu�e pr�c�demment
    * Effectue l'action inverse de celle qui appelle cette fonction
    */
    void undoC();
    /*!
    * \brief Recommence l'action effectu�e pr�c�demment
    * Effectue l'action exacte de celle qui appelle cette fonction
    */
    void redoC();

private slots:
    //fonctions de traitement des boutons
    /*!
    * \brief Affiche 0 lorsque l'on clique dessus
    */
    void on_pushButton_0_clicked();
    /*!
    * \brief Affiche 1 lorsque l'on clique dessus
    */
    void on_pushButton_1_clicked();
    /*!
    * \brief Affiche 2 lorsque l'on clique dessus
    */
    void on_pushButton_2_clicked();
    /*!
    * \brief Affiche 3 lorsque l'on clique dessus
    */
    void on_pushButton_3_clicked();
    /*!
    * \brief Affiche 4 lorsque l'on clique dessus
    */
    void on_pushButton_4_clicked();
    /*!
    * \brief Affiche 5 lorsque l'on clique dessus
    */
    void on_pushButton_5_clicked();
    /*!
    * \brief Affiche 6 lorsque l'on clique dessus
    */
    void on_pushButton_6_clicked();
    /*!
    * \brief Affiche 7 lorsque l'on clique dessus
    */
    void on_pushButton_7_clicked();
    /*!
    * \brief Affiche 8 lorsque l'on clique dessus
    */
    void on_pushButton_8_clicked();
    /*!
    * \brief Affiche 9 lorsque l'on clique dessus
    */
    void on_pushButton_9_clicked();
    /*!
    * \brief Affiche + lorsque l'on clique dessus
    */
    void on_pushButton_Plus_clicked();
    /*!
    * \brief Affiche - lorsque l'on clique dessus
    */
    void on_pushButton_Moins_clicked();
    /*!
    * \brief Affiche * lorsque l'on clique dessus
    */
    void on_pushButton_Mul_clicked();
    /*!
    * \brief Affiche / lorsque l'on clique dessus
    */
    void on_pushButton_DIV_clicked();
    /*!
    * \brief Dupplique le sommet de la pile
    */
    void on_pushButton_DUP_clicked();
    /*!
    * \brief Vide la pile
    */
    void on_pushButton_CLEAR_clicked();
    /*!
    * \brief Supprime le sommet de la pile
    */
    void on_pushButton_DROP_clicked();
    /*!
    * \brief Evalue l'expression au sommet de la pile
    */
    void on_pushButton_EVAL_clicked();
    /*!
    * \brief Affiche , lorsque l'on clique dessus
    */
    void on_pushButton_Virgule_clicked();
    /*!
    * \brief Rentre dans la pile ce que l'on a rentr�
    */
    void on_pushButton_Enter_clicked();
    /*!
    * \brief Annule la derni�re action effectu�e
    */
    void on_pushButton_Annuler_clicked();
    /*!
    * \brief Reeffectue une action annul�e
    */
    void on_pushButton_Retablir_clicked();
    /*!
    * \brief Calcule le cos du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_COS_clicked();
    /*!
    * \brief Calcule le cosh du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_COSH_clicked();
    /*!
    * \brief Calcule le sin du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_SIN_clicked();
    /*!
    * \brief Calcule le sinh du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_SINH_clicked();
    /*!
    * \brief Calcule le tan du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_TAN_clicked();
    /*!
    * \brief Calcule le tanh du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_TANH_clicked();
    /*!
    * \brief D�pile deux fois le sommet de la pile, calcule le modulo du premier sommet par le deuxi�me et empile le r�sultat
    */
    void on_pushButton_MOD_clicked();
    /*!
    * \brief Calcule le fact du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_FACT_clicked();
    /*!
    * \brief D�pile deux fois le sommet de la pile, calcule le premier sommet puissance le deuxi�me et empile le r�sultat
    */
    void on_pushButton_POW_clicked();
    /*!
    * \brief Calcule le logarithme n�p�rien du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_LN_clicked();
    /*!
    * \brief Calcule le logarithme d�cimal du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_LOG_clicked();
    /*!
    * \brief Calcule la racine carr� du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_SQRT_clicked();
    /*!
    * \brief Calcule le carr� du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_SQR_clicked();
    /*!
    * \brief Calcule le cube du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_CUBE_clicked();
    /*!
    * \brief Calcule l'inverse du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_INV_clicked();
    /*!
    * \brief Change le signe du sommet de la pile lorsque l'on clique dessus
    */
    void on_pushButton_SIGN_clicked();
    /*!
    * \brief Calcule la moyenne des n premiers constantes de la pile lorsque l'on clique dessus,
    * on demande � l'utilisateur sur combien de constantes l'on veut calculer la moyenne
    */
    void on_pushButton_MEAN_clicked();
    /*!
    * \brief Calcule la somme des n premi�res constantes de la pile lorsque l'on clique dessus,
    * on demande � l'utilisateur sur combien de constantes l'on veut calculer la somme
    */
    void on_pushButton_SUM_clicked();
    /*!
    * \brief Change de place deux constantes de la pile,
    * on demande � l'utilisateur quelles constantes il veut interchanger
    */
    void on_pushButton_SWAP_clicked();

    /*!
    * \brief g�re le raccourcis avec le bouton backspace
    */
    void effacer();
    /*!
    * \brief g�re l'affichage du clavier
    */
    void afficheClavier();
    /*!
    * \brief g�re le changement de mode d'utilisation
    */
    void changeMode(int m);
    /*!
    * \brief g�re l'utilisation de Complexe
    */
    void useComplexe();
    /*!
    * \brief g�re l'affichage du symbole repr�sentant les complexes
    */
    void ecrireComplexe();
    /*!
    * \brief g�re l'affichage des expressions
    */
    void ecrireExpression();
    /*!
    * \brief g�re l'affichage de la virgule
    */
    void ecrireVirgule();
    /*!
    * \brief g�re l'affichage de l'espace
    */
    void ecrireEspace();
    /*!
    * \brief g�re l'affichage de la pile
    */
    void changeAffichagePile();
    /*!
    * \brief g�re l'evaluation des expressions
    */
    void evaluer(Expression* expr);
    /*!
    * \brief g�re la fermeture du projet
    */
    void quitter();

private:
    Ui::MainWindow *ui;         /*!< Fen�tre */
    QUndoStack *undoStack;      /*!< Pile Annuler-retablir */
    QString* contenuList[20];   /*!< Liste d'affichage */
    Type typeMode;              /*!< Type de la constante d�sir�e */
    Type typeComplexe;          /*!< Type du complexe d�sir� */
    /*!
    * \brief Affiche le contenu de la pile
    */
    void affichePile();
    /*!
    * \brief Recharge le contexte de la pile � la derni�re utilisation
    */
    void initContexte();
};


/*!
* \class AddTexte
* \brief Classe pour l'ajout de texte
*/
class AddTexte : public QUndoCommand
{
public:
    /*!
    * \brief Constructeur de AddTexte
    */
    AddTexte(std::string s, MainWindow* w, QUndoCommand *parent = 0);

    /*!
    * \brief Efface du texte de la MainWindow
    * action inverse de la fonction AddTexte
    */
    void undo();
    /*!
    * \brief Ajoute du texte de la MainWindow
    * action identique � la fonction AddTexte
    */
    void redo();
private:
    int taille;         /*!< taille du texte � ajouter */
    QString chaine;     /*!< contenu de la chaine � ajouter */
    MainWindow* ptr;    /*!< pointeur sur la fenetre o� l'on va afficher le texte � ajouter */
};


/*!
* \class DelTexte
* \brief Classe pour la suppression de texte
*/
class DelTexte : public QUndoCommand
 {
 public:
    /*!
    * \brief Constructeur de DelTexte
    */
     DelTexte(std::string s, MainWindow* w, QUndoCommand *parent = 0);

     /*!
     * \brief Ajoute du texte de la MainWindow
     * action inverse de la fonction DelTexte
     */
     void undo();
     /*!
     * \brief Efface du texte de la MainWindow
     * action identique � la fonction DelTexte
     */
     void redo();

 private:
     QString chaine;        /*!< contenu de la chaine � supprimer */
     MainWindow* ptr;       /*!< la fenetre o� l'on va enlever le texte � supprimer */
 };


/*!
* \class AddPile
* \brief Classe pour la gestion des ajouts sur la pile
*/
class AddPile : public QUndoCommand
 {
 public:
    /*!
    * \brief Constructeur de AddPile
    */
     AddPile(Constante* c1, QUndoCommand *parent = 0);
     /*!
     * \brief D�piler
     * action inverse de la fonction AddPile
     */
     void undo();
     /*!
     * \brief Empiler
     * action identique � la fonction AddPile
     */
     void redo();

 private:
     Constante* a;          /*!< constante que l'on doit ajouter � la pile */
 };


/*!
* \class DelPile
* \brief Classe pour la gestion des suppressions sur la pile
*/
class DelPile : public QUndoCommand
 {
 public:
     /*!
     * \brief Constructeur de DelPile
     */
     DelPile(int i, QUndoCommand *parent = 0);
     /*!
      *  \brief Accesseur
      *  \return Premi�re constante d�pil�e
      */
     Constante* getA() {return a;}
     /*!
      *  \brief Accesseur
      *  \return Deuxi�me constante d�pil�e
      */
     Constante* getB() {return b;}
     /*!
     * \brief Empiler
     * action inverse de la fonction DelPile
     */
     void undo();
     /*!
     * \brief D�piler
     * action identique � la fonction DelPile
     */
     void redo();

 private:
     int nbConst;       /*!< nombre de constantes d�pil�es */
     Constante* a;      /*!< constante que l'on a supprim� de la pile */
     Constante* b;      /*!< constante que l'on a supprim� de la pile */
 };


/*!
* \class SwapPile
* \brief Classe pour la gestion des echanges sur la pile
*/
class SwapPile : public QUndoCommand
 {
 public:
     /*!
     * \brief Constructeur de SwapPile
     */
     SwapPile(int i, int j, QUndoCommand *parent = 0);
     /*!
     * \brief Change de place deux constantes choisies
     * action identique � la fonction SwapPile
     */
     void undo();
     /*!
     * \brief Change de place deux constantes choisies
     * action identique � la fonction SwapPile
     */
     void redo();

 private:
     int f, l;       /*!<  places dans la pile des constantes � �changer */
 };

/*!
* \brief permet de d�terminer si le contenu de s est un entier
*/
bool isEntier(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est un reel
*/
bool isReel(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est un rationnel
*/
bool isRationnel(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est un complexe
*/
bool isComplexe(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est une expression
*/
bool isExpression(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est un op�rateur binaire (+,-,* ...)
*/
bool operateur_binaire(const std::string& s);
/*!
* \brief permet de d�terminer si le contenu de s est un op�rateur unaire binaire (+,-,* ...)(ex : cos, sin ...)
*/
bool operateur_unaire(const std::string& s);
/*!
* \brief permet de d�terminer si un caract�re est pr�sent dans s
*/
bool estPresentChar(const char& c, const QString& s);
/*!
* \brief permet de d�terminer si s est vide
*/
bool estVide(const QString& s);
/*!
* \brief permet de connaitre le nombre d'occurence de c dans s
*/
int nbOccurences(const char& c, const QString& s);
/*!
* \brief permet de connaitre le type de Constante contenue dans le QString
*/
Type typeTexte(const QString& s);


#endif // MAINWINDOW_H
