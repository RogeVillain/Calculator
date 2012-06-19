#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

//Création de la Pile

Pile& P = Pile::donneInstance();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(750,410 );

    undoStack = new QUndoStack();

    for(int i = 0; i < 20; i++)
        contenuList[i] = NULL;

    typeMode = entier;
    typeComplexe = entier;

    //Définition des raccourcis clavier

    QShortcut* shortcut0 = new QShortcut(QKeySequence("0"), this);
    QShortcut* shortcut1 = new QShortcut(QKeySequence("1"), this);
    QShortcut* shortcut2 = new QShortcut(QKeySequence("2"), this);
    QShortcut* shortcut3 = new QShortcut(QKeySequence("3"), this);
    QShortcut* shortcut4 = new QShortcut(QKeySequence("4"), this);
    QShortcut* shortcut5 = new QShortcut(QKeySequence("5"), this);
    QShortcut* shortcut6 = new QShortcut(QKeySequence("6"), this);
    QShortcut* shortcut7 = new QShortcut(QKeySequence("7"), this);
    QShortcut* shortcut8 = new QShortcut(QKeySequence("8"), this);
    QShortcut* shortcut9 = new QShortcut(QKeySequence("9"), this);
    QShortcut* shortcutP = new QShortcut(QKeySequence("+"), this);
    QShortcut* shortcutM = new QShortcut(QKeySequence("-"), this);
    QShortcut* shortcutF = new QShortcut(QKeySequence("*"), this);
    QShortcut* shortcutD = new QShortcut(QKeySequence("/"), this);
    QShortcut* shortcutEval = new QShortcut(QKeySequence("Ctrl+e"), this);
    QShortcut* shortcutEnter = new QShortcut(QKeySequence(Qt::Key_Enter), this);
    QShortcut* shortcutReturn = new QShortcut(QKeySequence(Qt::Key_Return), this);
    QShortcut* shortcutAnnuler = new QShortcut(QKeySequence("Ctrl+z"), this);
    QShortcut* shortcutRetablir = new QShortcut(QKeySequence("Ctrl+y"), this);
    QShortcut* shortcutEffacer = new QShortcut(QKeySequence("Backspace"), this);
    QShortcut* shortcut$ = new QShortcut(QKeySequence("$"), this);
    QShortcut* shortcutExpr = new QShortcut(QKeySequence("@"), this);
    QShortcut* shortcutVirgule = new QShortcut(QKeySequence(","), this);
    QShortcut* shortcutPoint = new QShortcut(QKeySequence("."), this);
    QShortcut* shortcutClear = new QShortcut(QKeySequence("Ctrl+c"), this);
    QShortcut* shortcutEspace = new QShortcut(QKeySequence("Space"), this);

    //Connection des raccourcis claviers avec les Widgets

    QObject::connect(shortcut0, SIGNAL(activated()), this, SLOT(on_pushButton_0_clicked()));
    QObject::connect(shortcut1, SIGNAL(activated()), this, SLOT(on_pushButton_1_clicked()));
    QObject::connect(shortcut2, SIGNAL(activated()), this, SLOT(on_pushButton_2_clicked()));
    QObject::connect(shortcut3, SIGNAL(activated()), this, SLOT(on_pushButton_3_clicked()));
    QObject::connect(shortcut4, SIGNAL(activated()), this, SLOT(on_pushButton_4_clicked()));
    QObject::connect(shortcut5, SIGNAL(activated()), this, SLOT(on_pushButton_5_clicked()));
    QObject::connect(shortcut6, SIGNAL(activated()), this, SLOT(on_pushButton_6_clicked()));
    QObject::connect(shortcut7, SIGNAL(activated()), this, SLOT(on_pushButton_7_clicked()));
    QObject::connect(shortcut8, SIGNAL(activated()), this, SLOT(on_pushButton_8_clicked()));
    QObject::connect(shortcut9, SIGNAL(activated()), this, SLOT(on_pushButton_9_clicked()));
    QObject::connect(shortcutP, SIGNAL(activated()), this, SLOT(on_pushButton_Plus_clicked()));
    QObject::connect(shortcutM, SIGNAL(activated()), this, SLOT(on_pushButton_Moins_clicked()));
    QObject::connect(shortcutF, SIGNAL(activated()), this, SLOT(on_pushButton_Mul_clicked()));
    QObject::connect(shortcutD, SIGNAL(activated()), this, SLOT(on_pushButton_DIV_clicked()));
    QObject::connect(shortcutEval, SIGNAL(activated()), this, SLOT(on_pushButton_EVAL_clicked()));
    QObject::connect(shortcutEnter, SIGNAL(activated()), this, SLOT(on_pushButton_Enter_clicked()));
    QObject::connect(shortcutReturn, SIGNAL(activated()), this, SLOT(on_pushButton_Enter_clicked()));
    QObject::connect(shortcutAnnuler, SIGNAL(activated()), this, SLOT(on_pushButton_Annuler_clicked()));
    QObject::connect(shortcutRetablir, SIGNAL(activated()), this, SLOT(on_pushButton_Retablir_clicked()));
    QObject::connect(shortcutEffacer, SIGNAL(activated()), this, SLOT(effacer()));
    QObject::connect(shortcut$, SIGNAL(activated()), this, SLOT(ecrireComplexe()));
    QObject::connect(shortcutExpr, SIGNAL(activated()), this, SLOT(ecrireExpression()));
    QObject::connect(shortcutVirgule, SIGNAL(activated()), this, SLOT(ecrireVirgule()));
    QObject::connect(shortcutPoint, SIGNAL(activated()), this, SLOT(ecrireVirgule()));
    QObject::connect(shortcutClear, SIGNAL(activated()), this, SLOT(on_pushButton_CLEAR_clicked()));
    QObject::connect(shortcutEspace, SIGNAL(activated()), this, SLOT(ecrireEspace()));

    //QObject::connect(ui->actionAnnuler, SIGNAL(triggered()), undoStack, SLOT(undo()));
    QObject::connect(this, SIGNAL(undoC()), undoStack, SLOT(undo()));
    //QObject::connect(ui->actionRetablir, SIGNAL(triggered()), undoStack, SLOT(redo()));
    QObject::connect(this, SIGNAL(redoC()), undoStack, SLOT(redo()));

    //Connection des widgets avec les Slots modifiant l'affichage

    QObject::connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(quitter()));
    QObject::connect(ui->actionClavier, SIGNAL(triggered()), this, SLOT(afficheClavier()));
    QObject::connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeMode(int)));
    QObject::connect(ui->checkBox, SIGNAL(clicked()), this, SLOT(useComplexe()));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(changeAffichagePile()));

    initContexte();
}

MainWindow::~MainWindow()
{
    for(int i = 0; i < 20; i++)
        delete contenuList[i];
    delete ui;
}

//fonctions outil

bool estPresentChar(const char& c, const QString& s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == c) return true;
    }

    return false;
}
bool estVide(const QString& s)
{
    if(s == "") return true;
    else return false;
}
int nbOccurences(const char& c, const QString& s)
{
    int i = 0;

    for(int j = 0; j < s.length(); j++)
    {
        if(c == s[j])
            i++;
    }

    return i;

}
bool operateur_binaire(const string& s)
{
    return ((s=="+") || (s=="-") || (s=="*") || (s=="/") || (s=="pow") || (s=="mod"));
}

bool operateur_unaire(const std::string &s)
{
    return ((s == "cos") || (s=="sin") || (s=="tan") || (s=="cosh") || (s=="sinh") || (s=="tanh") || (s=="sqr") ||
            (s=="sqrt") || (s=="inv") || (s=="sign") || (s=="cube") || (s=="ln") || (s=="log") || (s=="factn")) ;
}
bool isExpression(const std::string& s)
{
    if ((s[0]==39) && (s[s.length()-1]==39))
        return true;
    else return false;
}
bool isEntier(const string& s)
{
    for(unsigned int i = 0; i < s.length(); i++)
    {
        if(!isdigit(s[i]))
            return false;
    }
    return true;
}

bool isReel(const string& s)
{
    int j = 0;
    for(unsigned int i =0; i < s.length(); i++)
    {
        if(s[i] == '.') j++;

        if(!isdigit(s[i]) && (s[i] != '.' || j > 1) && isdigit(s[i+1]))
            return false;
    }
    if(j == 1)
        return true;
    else
        return false;
}

bool isRationnel(const string& s)
{
    int j = 0;
    for(unsigned int i =0; i < s.length(); i++)
    {
        if(s[i] == '/') j++;

        if(!isdigit(s[i]) && ((s[i] != '/' || j > 1) || !isdigit(s[i+1])))
            return false;
    }
    if(j == 1)
        return true;
    else
        return false;
}


bool isComplexe(const string& s)
{
    int i = s.find_first_of('$');
    int j = s.find_last_of('$');

    if(i != j)
        return false;

    string s1 = s.substr(0, i);
    string s2 = s.substr(i+1);

    if(s1.length() <= 0 || s2.length() <=0)
        return false;

    if(isEntier(s1) && isEntier(s2))
        return true;
    else if(isReel(s1) && isReel(s2))
        return true;
    else if(isRationnel(s1) && isRationnel(s2))
        return true;

    return false;
}

Type typeTexte(const QString& s)
{
    string s1 = s.toStdString();
    if (isExpression(s1))
        return expression;
    else if(isEntier(s1))
        return entier;
    else if(isReel(s1))
        return reel;
    else if(isRationnel(s1))
        return rationnel;
    else if(isComplexe(s1))
        return complexe;

        return erreur;
}
void MainWindow::effacerTexte()
{
    if(!ui->textEdit->toPlainText().isEmpty()){
        QString tmp = ui->textEdit->toPlainText();
        int i = tmp.length();
        ui->textEdit->setPlainText(tmp.left(i-1));
    }
    else
    {
        LogSystem::printLog(LogMessage("Aucun caractere a effacer...", 1));
    }
}
void MainWindow::ajouterTexte(const QString& s)
{
    QString texte = ui->textEdit->toPlainText() + s;
    ui->textEdit->clear();
    ui->textEdit->setText(texte);
}

//Définition des slots des raccourcis claviers

void MainWindow::on_pushButton_0_clicked()
{
    undoStack->push(new AddTexte("0", this));
}
void MainWindow::on_pushButton_1_clicked()
{
    undoStack->push(new AddTexte("1", this));
}
void MainWindow::on_pushButton_2_clicked()
{
    undoStack->push(new AddTexte("2", this));
}
void MainWindow::on_pushButton_3_clicked()
{
    undoStack->push(new AddTexte("3", this));
}
void MainWindow::on_pushButton_4_clicked()
{
    undoStack->push(new AddTexte("4", this));
}
void MainWindow::on_pushButton_5_clicked()
{
    undoStack->push(new AddTexte("5", this));
}
void MainWindow::on_pushButton_6_clicked()
{
    undoStack->push(new AddTexte("6", this));
}
void MainWindow::on_pushButton_7_clicked()
{
    undoStack->push(new AddTexte("7", this));
}
void MainWindow::on_pushButton_8_clicked()
{
    undoStack->push(new AddTexte("8", this));
}
void MainWindow::on_pushButton_9_clicked()
{
    undoStack->push(new AddTexte("9", this));
}
void MainWindow::on_pushButton_Plus_clicked()
{
    if(estPresentChar('\'', ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("+", this));
    }
    else if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2)
    {
           DelPile* del = new DelPile(2);
           undoStack->push(del);
           undoStack->push(new AddPile(addition(typeMode, typeComplexe, del->getA(), del->getB())));
           affichePile();
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une addition", 2));
}
void MainWindow::on_pushButton_Moins_clicked()
{
    if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("-", this));
    }
    else if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2)
    {
        DelPile* del = new DelPile(2);
        undoStack->push(del);
        undoStack->push(new AddPile(soustraction(typeMode, typeComplexe, del->getA(), del->getB())));
           affichePile();
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une soustraction", 2));
}
void MainWindow::on_pushButton_Mul_clicked()
{
    if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("*", this));
    }
    else if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2)
    {
        DelPile* del = new DelPile(2);
        undoStack->push(del);
        undoStack->push(new AddPile(multiplication(typeMode, typeComplexe, del->getA(), del->getB())));
           affichePile();
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une multiplication", 2));
}
void MainWindow::on_pushButton_DIV_clicked()
{
    if((!estPresentChar('/', ui->textEdit->toPlainText()) || estPresentChar('\'', ui->textEdit->toPlainText()) || nbOccurences('/', ui->textEdit->toPlainText()) < 2) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("/", this));
    }
    else if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2)
    {
        DelPile* del = new DelPile(2);
        undoStack->push(del);
        undoStack->push(new AddPile(div(typeMode, typeComplexe, del->getA(), del->getB())));
           affichePile();
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une div", 2));
}
void MainWindow::on_pushButton_COS_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
           DelPile* del = new DelPile(1);
           undoStack->push(del);
           undoStack->push(new AddPile(cos(del->getA(), ui->radioButton->isChecked())));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("cos", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un cos", 2));
}
void MainWindow::on_pushButton_COSH_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(cosh(del->getA())));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("cosh", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un cos hyperbolique", 2));
}
void MainWindow::on_pushButton_SIN_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(sin(del->getA(), ui->radioButton->isChecked())));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("sin", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un sin", 2));
}
void MainWindow::on_pushButton_SINH_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(sinh(del->getA())));
           affichePile();
    }else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("sinh", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un sin hyperbolique", 2));
}
void MainWindow::on_pushButton_TAN_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(tan(del->getA(), ui->radioButton->isChecked())));
           affichePile();
    }else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("tan", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une tan", 2));
}
void MainWindow::on_pushButton_TANH_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(tanh(del->getA())));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("tanh", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une tan hyperbolique", 2));
}
void MainWindow::on_pushButton_MOD_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2)
    {
        DelPile* del = new DelPile(2);
        undoStack->push(del);
        undoStack->push(new AddPile(mod(del->getA(), del->getB())));
           affichePile();
    }else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("mod", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un mod", 2));
}
void MainWindow::on_pushButton_FACT_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(fact(del->getA())));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("fact", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une fact", 2));
}
void MainWindow::on_pushButton_POW_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 2 && typeMode != complexe)
    {
        DelPile* del = new DelPile(2);
        undoStack->push(del);
        undoStack->push(new AddPile(pow(del->getA(), del->getB(), typeMode)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("pow", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une pow", 2));
}
void MainWindow::on_pushButton_LN_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1 && typeMode != complexe)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(ln(del->getA(), typeMode)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("ln", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un log neperien", 2));
}
void MainWindow::on_pushButton_LOG_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1 && typeMode != complexe)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(log(del->getA(), typeMode)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("log", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un log decimal", 2));
}
void MainWindow::on_pushButton_SQRT_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1 && typeMode != complexe)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(sqrt(del->getA(), typeMode)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("sqrt", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour une sqrt sqr", 2));
}
void MainWindow::on_pushButton_SQR_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(sqr(del->getA(), typeMode, typeComplexe)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("sqr", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un sqr", 2));
}
void MainWindow::on_pushButton_CUBE_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(cube(del->getA(), typeMode, typeComplexe)));
           affichePile();
    }else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("cube", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un cube", 2));
}
void MainWindow::on_pushButton_INV_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1 && typeMode != complexe)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(inv(del->getA(), typeMode)));
           affichePile();
    }
    else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("inv", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un inv", 2));
}
void MainWindow::on_pushButton_SIGN_clicked()
{
    if(estVide(ui->textEdit->toPlainText()) && P.getSize() >= 1)
    {
        DelPile* del = new DelPile(1);
        undoStack->push(del);
        undoStack->push(new AddPile(sign(del->getA(), typeMode, typeComplexe)));
           affichePile();
    }else if(estPresentChar('\'', ui->textEdit->toPlainText()) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("sign", this));
    }
    else
        LogSystem::printLog(LogMessage("Pas assez d'argument pour un changement de sign", 2));
}
void MainWindow::on_pushButton_DUP_clicked()
{
    if(!P.isEmpty()){
        undoStack->push(new AddPile(P.duplicate()));
        affichePile();
    }
    else
        LogSystem::printLog(LogMessage("Pas d'�lement a dupliquer", 2));
}
void MainWindow::on_pushButton_CLEAR_clicked()
{
    P.dropPile();
    undoStack->clear();
    affichePile();
    LogSystem::printLog(LogMessage("La pile est videe", 3));
}
void MainWindow::on_pushButton_DROP_clicked()
{
    if(!P.isEmpty()){
    undoStack->push(new DelPile(1));
    affichePile();}
    else
        LogSystem::printLog(LogMessage("Pas d'�lement �  depiler", 2));
}
void MainWindow::on_pushButton_MEAN_clicked()
{
    if(P.getSize() == 0) return;

    int i = 0;
    i = QInputDialog::getInteger(this, "MEAN", "Entrez l'argument :", 1, 1, P.getSize());

    for(int j = 1; j < i; j++)
    {
        if(P.sommetPile()->getType() != expression)
        {
            DelPile* del = new DelPile(2);
            undoStack->push(del);
            if(del->getB()->getType() != expression)
            {
                undoStack->push(new AddPile(new Reel(*toReel(del->getA()) + *toReel(del->getB()))));
                if(j+1 == i)
                {
                    Reel* temp = dynamic_cast<Reel*>(P.sommetPile());
                    temp->setVal(temp->getVal()/(i));
                }
            }
            else
            {
                emit undoC();
                if(j > 1){
                Reel* temp = dynamic_cast<Reel*>(P.sommetPile());
                temp->setVal(temp->getVal()/(j));}
                affichePile();
                return;
            }
        }
        else
            return;
    }

    affichePile();

}
void MainWindow::on_pushButton_SUM_clicked()
{
    if(P.getSize() == 0) return;

    int i = 0;
    i = QInputDialog::getInteger(this, "SUM", "Entrez l'argument :", 1, 1, P.getSize());

    for(int j = 1; j < i; j++)
    {
        if(P.sommetPile()->getType() != expression)
        {
            DelPile* del = new DelPile(2);
            undoStack->push(del);
            if(del->getB()->getType() != expression)
            {
                undoStack->push(new AddPile(new Reel(*toReel(del->getA()) + *toReel(del->getB()))));
            }
            else
            {
                emit undoC();
                affichePile();
                return;
            }
        }
        else
            return;
    }

    affichePile();

}
void MainWindow::on_pushButton_SWAP_clicked()
{
    if(P.getSize() < 2) return;

    int i = 0, j = 0;
    i = QInputDialog::getInteger(this, "SWAP", "Entrez le premier argument :", 1, 1, P.getSize());
    j = QInputDialog::getInteger(this, "SWAP", "Entrez le second argument :", 1, 1, P.getSize());

    if(i == j) return;
    else if(i > j)
    {
        int temp = i;
        i = j;
        j = temp;
    }

    undoStack->push(new SwapPile(i, j));

    affichePile();
}
void MainWindow::on_pushButton_Annuler_clicked()
{
        emit undoC();
        affichePile();
}
void MainWindow::on_pushButton_Retablir_clicked()
{
        emit redoC();
        affichePile();
}
void MainWindow::on_pushButton_Enter_clicked()
{
    if(!estVide(ui->textEdit->toPlainText()))
    {
        Type temp = typeTexte(ui->textEdit->toPlainText());

        if (temp == expression)
                {
                    string chaine = ui->textEdit->toPlainText().toStdString();
                    undoStack->push(new DelTexte(ui->textEdit->toPlainText().toStdString(), this));
                    undoStack->push(new AddPile(FactoryConst::createConstant(chaine,temp)));
                    LogSystem::printLog(LogMessage("Insertion de l'expression : " + chaine, 1));
                    ui->textEdit->clear();
                 }
        else if(typeMode != complexe && temp != erreur)
        {
            string chaine = ui->textEdit->toPlainText().toStdString();
            undoStack->push(new DelTexte(ui->textEdit->toPlainText().toStdString(), this));

            if(temp == complexe)
                undoStack->push(new AddPile(FactoryConst::createConstant(chaine, typeMode, temp, typeComplexe)));
            else
                undoStack->push(new AddPile(FactoryConst::createConstant(chaine, typeMode, temp)));
            LogSystem::printLog(LogMessage("Insertion de la constante : " + chaine, 1));
            ui->textEdit->clear();
        }
        else if(temp == complexe)
        {
            int i = ui->textEdit->toPlainText().toStdString().find_first_of('$');
            string chaine = ui->textEdit->toPlainText().toStdString();
            string a = ui->textEdit->toPlainText().toStdString().substr(0, i);
            Type temp2 = typeTexte(QString(a.c_str()));
            undoStack->push(new DelTexte(ui->textEdit->toPlainText().toStdString(), this));
            undoStack->push(new AddPile(FactoryConst::createConstant(chaine, typeMode, temp, typeComplexe, temp2)));
            LogSystem::printLog(LogMessage("Insertion du complexe : " + chaine, 1));
            ui->textEdit->clear();
        }
        else if(temp == erreur)
        {
            ui->textEdit->clear();
            undoStack->push(new AddTexte("Expression non valide...", this));
            LogSystem::printLog(LogMessage("Tentative d'insertion d'un element non valide", 3));
        }
    }
    else if(!P.isEmpty())
        undoStack->push(new AddPile(P.duplicate()));

    affichePile();
}
void MainWindow::on_pushButton_EVAL_clicked()
{
    /*Quand on clique sur EVAL, si la zone de texte contient une expression,
    on l'évalue. Sinon, si la zone de texte contient une constante, on ne fait rien.
    Sinon, si la zone de texte est vide mais que le sommet de la pile est une expression,
    on dépile cette expression pour l'évaluer.*/

    if (!estVide(ui->textEdit->toPlainText()))
    {
        if (typeTexte(ui->textEdit->toPlainText())== expression)
        {
            //on appelle la fonction qui évalue cette expression :
            Expression* temp = new Expression(ui->textEdit->toPlainText().toStdString());
            ui->textEdit->clear();
            evaluer(temp);
        }
    }
    else
    {
        if (!P.isEmpty())
        {
            if (P.sommetPile()->getType()==expression)
            {
                DelPile* del = new DelPile(1);
                undoStack->push(del);
                Constante* a = del->getA();

                Expression* temp2 = dynamic_cast<Expression*>(a);
                evaluer(temp2);
            }
            else
            {
                ui->textEdit->setText(QString::fromStdString(P.popPile()->getChain()));
            }
        }
    }

    affichePile();
}
void MainWindow::initContexte()
{
    QSettings settings("mesoptions.ini", QSettings::IniFormat);
    ui->actionClavier->setChecked(settings.value("clavier", true).toBool());
    this->afficheClavier();
    ui->checkBox->setChecked(settings.value("complexe", false).toBool());
    this->useComplexe();
    ui->comboBox->setCurrentIndex(settings.value("mode", 0).toInt());
    if(settings.value("degre", true).toBool())
        ui->radioButton->setChecked(true);
    else
        ui->radioButton_2->setChecked(true);

    vector<Constante*> temp;
    stringstream* ss;
    string s;
    for(int i = 0; i < settings.value("taillePile").toInt(); i++)
    {
        ss = new stringstream;
        *ss << i << "/valeur";
        s = settings.value(QString(ss->str().c_str())).toString().toStdString();
        Type t = typeTexte(QString(s.c_str()));

        if(t == entier || t == rationnel || t == reel)
        {
            temp.push_back(FactoryConst::createConstant(s, t, t));
        }
        else if(t == complexe)
        {
            int i = s.find_first_of('$');
            string a = s.substr(0, i);
            Type temp2 = typeTexte(QString(a.c_str()));
            temp.push_back(FactoryConst::createConstant(s, t, t, temp2, temp2));
        }
        else
        {
            temp.push_back(FactoryConst::createConstant(s, t));
        }

        delete ss;
    }

    while(!temp.empty())
    {
        P.pushPile(temp.back());
        temp.pop_back();
    }

    affichePile();
}
void MainWindow::quitter()
{
    QSettings settings("mesoptions.ini", QSettings::IniFormat);
    settings.setValue("clavier", ui->actionClavier->isChecked());
    settings.setValue("complexe", ui->checkBox->isChecked());
    settings.setValue("mode", ui->comboBox->currentIndex());
    settings.setValue("degre", ui->radioButton->isChecked());
    settings.setValue("taillePile", P.getSize());

    int i = 0;

    while(!P.isEmpty())
    {
        stringstream ss;
        ss << i << "/valeur";
        settings.setValue(QString(ss.str().c_str()), QString(P.sommetPile()->getChain().c_str()));
        stringstream ss1;
        ss1 << i << "/type";
        settings.setValue(QString(ss1.str().c_str()), P.sommetPile()->getType());
        if(P.sommetPile()->getType() == complexe){
            stringstream ss2;
            ss2 << i << "/typeComplexe";
            Complexe* temp = dynamic_cast<Complexe*>(P.sommetPile());
            settings.setValue(QString(ss2.str().c_str()), temp->get_complexe_type_contenu());
        }
        P.popPile();
        i++;
    }

    close();
}
void MainWindow::on_pushButton_Virgule_clicked()
{
    ecrireVirgule();
}

//Définition des Slots Perso

void MainWindow::afficheClavier()
{
    if(ui->actionClavier->isChecked())
    {
        ui->pushButton_0->setVisible(true);
        ui->pushButton_1->setVisible(true);
        ui->pushButton_2->setVisible(true);
        ui->pushButton_3->setVisible(true);
        ui->pushButton_4->setVisible(true);
        ui->pushButton_5->setVisible(true);
        ui->pushButton_6->setVisible(true);
        ui->pushButton_7->setVisible(true);
        ui->pushButton_8->setVisible(true);
        ui->pushButton_9->setVisible(true);
        ui->pushButton_Enter->setVisible(true);
        ui->pushButton_EVAL->setVisible(true);
        ui->pushButton_Plus->setVisible(true);
        ui->pushButton_Moins->setVisible(true);
        ui->pushButton_Mul->setVisible(true);
        ui->pushButton_DIV->setVisible(true);
        ui->pushButton_Virgule->setVisible(true);
    }
    else
    {
        ui->pushButton_0->setVisible(false);
        ui->pushButton_1->setVisible(false);
        ui->pushButton_2->setVisible(false);
        ui->pushButton_3->setVisible(false);
        ui->pushButton_4->setVisible(false);
        ui->pushButton_5->setVisible(false);
        ui->pushButton_6->setVisible(false);
        ui->pushButton_7->setVisible(false);
        ui->pushButton_8->setVisible(false);
        ui->pushButton_9->setVisible(false);
        ui->pushButton_Enter->setVisible(false);
        ui->pushButton_EVAL->setVisible(false);
        ui->pushButton_Plus->setVisible(false);
        ui->pushButton_Moins->setVisible(false);
        ui->pushButton_Mul->setVisible(false);
        ui->pushButton_DIV->setVisible(false);
        ui->pushButton_Virgule->setVisible(false);
    }
}
void MainWindow::effacer()
{
    if(!ui->textEdit->toPlainText().isEmpty()){
    undoStack->push(new DelTexte(&ui->textEdit->toPlainText().toStdString().at(ui->textEdit->toPlainText().length()-1), this));
    }
}
void MainWindow::changeMode(int m)
{
    if(m != 0){
        ui->pushButton_MOD->setDisabled(true);
        ui->pushButton_FACT->setDisabled(true);
    }
    else if(!ui->checkBox->isChecked()){
        ui->pushButton_MOD->setDisabled(false);
        ui->pushButton_FACT->setDisabled(false);
    }

    if(m == 0 && ui->checkBox->isChecked())
        typeComplexe = entier;
    else if(m == 1 && ui->checkBox->isChecked())
        typeComplexe = rationnel;
    else if(m == 2 && ui->checkBox->isChecked())
        typeComplexe = reel;
    else if(m == 0 && !ui->checkBox->isChecked())
        typeMode = entier;
    else if(m == 1 && !ui->checkBox->isChecked())
        typeMode = rationnel;
    else if(m == 2 && !ui->checkBox->isChecked())
        typeMode = reel;

}
void MainWindow::useComplexe()
{
    bool temp = ui->checkBox->isChecked();

    //ui->pushButton_DIV->setDisabled(temp);
    ui->pushButton_POW->setDisabled(temp);
    ui->pushButton_COS->setDisabled(temp);
    ui->pushButton_COSH->setDisabled(temp);
    ui->pushButton_LN->setDisabled(temp);
    ui->pushButton_LOG->setDisabled(temp);
    ui->pushButton_SIN->setDisabled(temp);
    ui->pushButton_SINH->setDisabled(temp);
    ui->pushButton_INV->setDisabled(temp);
    ui->pushButton_TAN->setDisabled(temp);
    ui->pushButton_TANH->setDisabled(temp);
    ui->pushButton_SQRT->setDisabled(temp);

    if(ui->comboBox->currentIndex() != 0 && temp != true)
    {
        ui->pushButton_MOD->setDisabled(true);
        ui->pushButton_FACT->setDisabled(true);
    }
    else
    {
        ui->pushButton_MOD->setDisabled(temp);
        ui->pushButton_FACT->setDisabled(temp);
    }

    if(temp == true){
        typeMode = complexe;

        if(ui->comboBox->currentIndex() == 0)
            typeComplexe = entier;
        else if(ui->comboBox->currentIndex() == 1)
            typeComplexe = rationnel;
        else if(ui->comboBox->currentIndex() == 2)
            typeComplexe = reel;
    }
    else{
        if(ui->comboBox->currentIndex() == 0)
            typeMode = entier;
        else if(ui->comboBox->currentIndex() == 1)
            typeMode = rationnel;
        else if(ui->comboBox->currentIndex() == 2)
            typeMode = reel;
    }
}
void MainWindow::ecrireComplexe()
{
    if(ui->checkBox->isChecked() && ((!estPresentChar('$', ui->textEdit->toPlainText())) || estPresentChar('\'', ui->textEdit->toPlainText())) && !estVide(ui->textEdit->toPlainText()))
    {
        undoStack->push(new AddTexte("$", this));
    }
}
void MainWindow::ecrireExpression()
{
    if(nbOccurences('\'', ui->textEdit->toPlainText()) < 2){
        undoStack->push(new AddTexte("'", this));
    }
}
void MainWindow::ecrireVirgule()
{
    if((!estPresentChar('.', ui->textEdit->toPlainText()) || estPresentChar('$', ui->textEdit->toPlainText())))
    {
        undoStack->push(new AddTexte(".", this));
    }
}
void MainWindow::ecrireEspace()
{
    if((estPresentChar('\'', ui->textEdit->toPlainText())))
    {
        undoStack->push(new AddTexte(" ", this));
    }
}
void MainWindow::changeAffichagePile()
{
        affichePile();
}
void MainWindow::affichePile()
{
    if(!P.isEmpty())
    {
        int j = 0;
        vector<Constante*> temp;
        while(!P.isEmpty())
        {
            if(j < 20)
                contenuList[j] = new QString(P.sommetPile()->getChain().c_str());
            j++;
            temp.push_back(P.popPile());
        }

        while(!temp.empty())
        {
            P.pushPile(temp.back());
            temp.pop_back();
        }

        ui->listWidget->clear();

        for(int i = 0; contenuList[i] != NULL && i < P.getSize(); i++)
        {
            if(i >= P.getSize() - ui->spinBox->value())
                ui->listWidget->insertItem(i, *(contenuList[P.getSize()-i-1]));
        }

    }
    else
        ui->listWidget->clear();
}

//fonctions liées �  la classe AddTexte

AddTexte::AddTexte(std::string s, MainWindow* w, QUndoCommand *parent) : QUndoCommand(parent)
{
    chaine = s.c_str();
    taille = chaine.length();
    ptr = w;
}
void AddTexte::undo()
{
    for(int i = 0; i < taille; i++)
        ptr->effacerTexte();
}
void AddTexte::redo()
{
    ptr->ajouterTexte(chaine);
}

//fonctions liées �  la classe DelTexte

DelTexte::DelTexte(std::string s, MainWindow* w, QUndoCommand *parent) : QUndoCommand(parent)
{
    chaine = s.c_str();
    ptr = w;
}
void DelTexte::undo()
{
    ptr->ajouterTexte(chaine);
}
void DelTexte::redo()
{
    for(int i = 0; i < chaine.length(); i++)
        ptr->effacerTexte();
}

//fonctions liées �  la classe AddPile

AddPile::AddPile(Constante* c1, QUndoCommand *parent): QUndoCommand(parent), a(c1)
{

}
void AddPile::undo()
{
    P.popPile();
}
void AddPile::redo()
{
    P.pushPile(a);
}

//fonctions liées �  la classe DelPile

DelPile::DelPile(int i, QUndoCommand *parent): QUndoCommand(parent),  nbConst(i), a(0), b(0)
{

}
void DelPile::undo()
{
    if(b != 0)
        P.pushPile(b);
    if(a != 0)
        P.pushPile(a);
}
void DelPile::redo()
{
    a = P.popPile();
    if(nbConst == 2)
        b = P.popPile();
}

//fonctions liées �  la classe SwapPile

SwapPile::SwapPile(int i, int j, QUndoCommand *parent) : QUndoCommand(parent)
{
    f = i;
    l = j;
}

void SwapPile::redo()
{
    P.swap(f, l);
}

void SwapPile::undo()
{
    P.swap(f, l);
}

void MainWindow::evaluer(Expression* expr)
{
    std::string s;
    std::string chaine = expr->getExpr();
    chaine.erase(0,1); //on supprime le premier caractère de la chaîne
    chaine.erase(chaine.length(),1); // on supprime le dernier caractère

    while(chaine[0]!=39)
        //tant qu'on est pas arrivés au bout de l'expression
    {




        if (chaine[0]!=32)
        {
            /*Si le caractère est un opérateur, on doit dépiler deux constantes
            Sinon, on empile la constante*/

            s.push_back(chaine[0]);
            if ((chaine[1]==39) || (chaine[1]==32))
                /* si le caractère suivant est un espace ou une apostrophe
                Alors s contient un nombre/opérateur complet*/
            {

                if (operateur_binaire(s))
                {
                    if (P.getSize() < 2)
                    {
                        ui->textEdit->setText(QString::fromStdString("'" + chaine));

                    }
                    else
                    {
                        DelPile* del = new DelPile(2);
                        undoStack->push(del);

                        Constante* temp1 = del->getA();
                        Constante* temp2 = del->getB();

                        if (s=="+")
                            undoStack->push(new AddPile(addition(typeMode, typeComplexe, temp1, temp2)));

                        else if (s=="-")
                             undoStack->push(new AddPile(soustraction(typeMode, typeComplexe, temp1, temp2)));

                        else if (s=="*")
                             undoStack->push(new AddPile(multiplication(typeMode, typeComplexe, temp1, temp2)));

                        else if (s=="/")
                             undoStack->push(new AddPile(div(typeMode, typeComplexe, temp1, temp2)));

                        else if (s=="mod")
                             undoStack->push(new AddPile(mod(temp1,temp2)));

                        else if (s=="pow")
                            undoStack->push(new AddPile(pow(temp1,temp2,typeMode)));


                    }
                } //fin du if(operateur_binaire(s))


                else if (operateur_unaire(s))
                {
                    /* Si s est un opérateur unaire, on a besoin de dépiler une seule constante */
                    if (P.getSize() < 1)
                    {
                        ui->textEdit->setText(QString::fromStdString("'" + chaine));

                    }
                    else
                    {
                        DelPile* del = new DelPile(1);
                        undoStack->push(del);

                        Constante* temp1 = del->getA();

                        if (s=="cos")
                            undoStack->push(new AddPile(cos(temp1,ui->radioButton->isChecked())));

                        else if (s=="sin")
                            undoStack->push(new AddPile(sin(temp1,ui->radioButton->isChecked())));

                        else if (s=="tan")
                            undoStack->push(new AddPile(tan(temp1,ui->radioButton->isChecked())));

                        else if (s=="cosh")
                            undoStack->push(new AddPile(cosh(temp1)));

                        else if (s=="sinh")
                            undoStack->push(new AddPile(sinh(temp1)));

                        else if (s=="tanh")
                            undoStack->push(new AddPile(tanh(temp1)));

                        else if (s=="ln")
                            undoStack->push(new AddPile(ln(temp1,typeMode)));

                        else if (s=="log")
                            undoStack->push(new AddPile(log(temp1,typeMode)));

                        else if (s=="sqr")
                            undoStack->push(new AddPile(sqr(temp1,typeMode,typeComplexe)));

                        else if (s=="sqrt")
                            undoStack->push(new AddPile(sqrt(temp1,typeMode)));

                        else if (s=="cube")
                            undoStack->push(new AddPile(cube(temp1,typeMode,typeComplexe)));

                        else if (s=="fact")
                            undoStack->push(new AddPile(fact(toEntier(temp1))));

                        else if (s=="sign")
                            undoStack->push(new AddPile(sign(temp1,typeMode,typeComplexe)));

                        else if (s=="inv")
                            undoStack->push(new AddPile(inv(temp1,typeMode)));


                    }
                } //fin if opérateur unaire


                else
                {
                    /*Si s est une constante, on l'empile*/
                    Type temp = typeTexte(QString::fromStdString(s));

                    if(typeMode != complexe && temp != erreur)
                    {
                        if(temp == complexe)
                            undoStack->push(new AddPile(FactoryConst::createConstant(s, typeMode, temp, typeComplexe)));
                        else
                            undoStack->push(new AddPile(FactoryConst::createConstant(s, typeMode, temp)));

                    }
                    else if(temp == complexe)
                    {
                        int j = s.find_first_of('$');
                        string a = s.substr(0, j);
                        Type temp2 = typeTexte(QString(a.c_str()));
                        undoStack->push(new AddPile(FactoryConst::createConstant(s, typeMode, temp, typeComplexe, temp2)));

                    }
                    else if(temp == erreur)
                    {
                        ui->textEdit->setText("Expression non valide...");
                    }
                }
                s.clear(); //on vide s pour commencer un nouveau nombre/opérateur
            } //fin du if : caractère suivant = espace ou apostrophe
        } //fin du if : le caractère n'est pas un espace

        chaine.erase(0,1); //on élimine un nouveau caractère de la chaine

    } //fin du while
}
