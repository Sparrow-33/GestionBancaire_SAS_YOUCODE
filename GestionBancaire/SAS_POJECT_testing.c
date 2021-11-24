#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct accounts
{
    char CIN[5];
    char Nom[10];
    char prenom[10];
    float montant;
    int accntId;
};

void makeAccount();
void displayAccounts();
void displaySingleAccount(int i);
void initSolde();
void retraitFunc();
void depotFunc();
void ascendentReferencedFunc();
void ascendentFunc();
void descendentFunc();
void descendentReferencedFunc();
void searchByCin();
void fidelityFunc();
void displayMenu();
void moyenneMontants();
void transaction();
int checkCIN(char *alpha);

int total;

struct accounts client[5];

int main()
{

    initSolde();
    displayMenu();
}

//******  INITIALIZE ACCOUNT ***************

void initSolde()
{
    int i;

    for (i = 0; i < total; i++)
    {
        client[i].montant = 0;
    }
}

//******   Create Compte ***************

void makeAccount()
{
    int i = 0, numofaccount;

    printf("\n--- Processus de Creation de  comptes ---\n\n");

    printf("> Combient de comptes voulez-vous creer ? \n\n-> ");
    scanf("%d", &numofaccount);

    total = numofaccount;

    for (i = 0; i < numofaccount; i++)
    {

        printf("--- Creation de compte %d\n\n", i + 1);

        printf("\n-> Account ID : ");
        scanf("%d", &client[i].accntId);

        printf("\n-> CIN : ");
        scanf("%s", &client[i].CIN);

        printf("\n-> Nom : ");
        scanf("%s", &client[i].Nom);

        printf("\n-> Prenom : ");
        scanf("%s", &client[i].prenom);

        printf("\n-> Montant : ");
        scanf("%f", &client[i].montant);

        printf("\n*** Votre Compte a ete cree avec succes ***\n");
    }

    displayMenu();
}

// =========== depot ========================

void depotFunc()
{
    int i = 0, index, id, found = 0;
    float preStatus, depot;
    char compare[10];

    printf("\n\n\t--- Processus de depot de l argent ---\n");

    do
    {
        /* code */

        printf("\nEnter CIN du Client :\n");
        scanf("%s", &compare);

        for (i = 0; i < total; i++)
        {
            if (strcmp(client[i].CIN, compare) == 0)
            {
                index = i;
                found = 1;
                break;
            }
        }
    } while (found == 0);

    preStatus = client[index].montant;
    printf("\n--- Compte Trouve ! ---\n");

    displaySingleAccount(index);

    printf("\n Enter votre depot\n-->");
    scanf("%f", &depot);

    client[index].montant += depot;

    printf("\nVoter montant a ete %f", preStatus);

    printf("\nVoter montant a devenu %f", client[index].montant);

    printf("\nOperation faite avec succes ! \n");

    displayMenu();
}

//========== Displaying ALL account info ====================

void displayAccounts()
{
    int i = 0;
    printf("\n\t--- Affichage des Infos des Comptes disponible ---\n");

    for (i = 0; i < total; i++)
    {
        printf("\n--- Compte %d\n", i + 1);
        printf("> Numero de compte : %d", client[i].accntId);
        printf("\n> CIN du Client : %s", client[i].CIN);
        printf("\n> Nom du client : %s", client[i].Nom);
        printf("\n> Prenom du client : %s", client[i].prenom);
        printf("\n> Montant : %f", client[i].montant);
    }
}

//========== Displaying ONE account info ====================


void displaySingleAccount(int acountIndex)
{
    printf("\n--- Affichage des Infos du Compte  ---\n");

    printf("\n--- Compte %d\n", acountIndex);
    printf("> Numero de compte : %d", client[acountIndex].accntId);
    printf("\n> CIN du Client : %s", client[acountIndex].CIN);
    printf("\n> Nom du client : %s", client[acountIndex].Nom);
    printf("\n> Prenom du client : %s", client[acountIndex].prenom);
    printf("\n> Montant : %f", client[acountIndex].montant);
}

//========  Tire ===========================

void retraitFunc()
{
    int i = 0, index, id, found = 0;
    float preStatus, depot;
    char compare[10];

    printf("\n\n--- Processus de retrait de l argent ---\n");

    do
    {
        /* code */

        printf("\nEnter CIN du Client :\n");
        scanf("%s", &compare);

        for (i = 0; i < total; i++)
        {
            if (strcmp(client[i].CIN, compare) == 0)
            {
                index = i;
                found = 1;
                break;
            }
        }
    } while (found == 0);

    preStatus = client[index].montant;
    printf("\n--- Compte Trouve ! ---\n");

    displaySingleAccount(index);
jump:
    printf("\n Enter votre depot\n-->");
    scanf("%f", &depot);

    if (depot <= client[index].montant)
    {
        client[index].montant -= depot;

        printf("\nVoter montant a ete %f", preStatus);

        printf("\nVoter montant a devenu %f", client[index].montant);

        printf("\nOperation faite avec succes ! \n");
    }
    else
    {
        printf("\n Solde Insuffisant !  ");
        goto jump;
    }
}

//======  DISPLAYING MENU  ============================

void displayMenu()
{
    int choice,demo;

    printf("\n\t---  MENU  ---\n");

    printf("\n> [1] Creer un / des Comptes");
    printf("\n> [2] Operations sur Comptes");
    printf("\n> [3] Affichage");
    printf("\n> [4] Fidelisation");
    printf("\n> [5] Quitter");
    printf("\n\n--> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        makeAccount();
        break;
    case 2:
        printf("\n--- Operation ---\n\n");
        printf("\n> [1] Depot");
        printf("\n> [2] Retrait");
        printf("\n> [3] Calcul de la moyenne");
        printf("\n> [4] Transaction");
        printf("\n\n--> ");
        scanf("%d", &choice); 
        switch (choice)
        {
        case 1:
            depotFunc();
            printf("\n");
            system("pause");
            displayMenu();
            break;
        case 2:
            retraitFunc();
            printf("\n");
            system("pause");
            displayMenu();
            break;
        case 3:
            moyenneMontants();
            printf("\n");
            system("pause");
            displayMenu();  
            break;
        case 4:
            transaction();
            printf("\n");
            system("pause");
            displayMenu();  
        default:
            break;
        }

    case 3:
        printf("\n--- Affichage ---\n\n");
        printf("\n> [1] Par Ordre Ascendant");
        printf("\n> [2] Par Ordre Descendant");
        printf("\n> [3] Par Ordre Ascendant + Reference");
        printf("\n> [4] Par Ordre Descendant + Reference");
        printf("\n> [5] Recherche par CIN");
        printf("\n--> ");
        scanf("%d", &demo);
        switch (demo)
        {
        case 1:
            ascendentFunc();
            displayAccounts();
            displayMenu();
            printf("\n");
            break;
        case 2:
            descendentFunc();
            displayAccounts();
            displayMenu();
            break;
        case 3:
            ascendentReferencedFunc();
            displayMenu();
            
            break;
        case 4:
            descendentReferencedFunc();
            displayMenu();
            break;
        case 5:
            searchByCin();
            displayMenu();
            break;
        default:
            break;
        }
        break;


    case 4:
        fidelityFunc();
        displayMenu();
        break;
    case 5:
        exit(0);
        break;
    default:
        break;
    }
}

//=========  Tri Ascendent  =============

void ascendentFunc()
{
    
     system("pause");
    int i, j;
    struct accounts new;

    for (i = 0; i < total - 1; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (client[i].montant > client[j].montant)
            {
                new = client[i];
                client[i] = client[j];
                client[j] = new;
            }
        }
    }

     system("pause");

}

//=========  Tri descendent  =============

void descendentFunc()
{
    int i, j;
    struct accounts new;

    for (i = 0; i < total - 1; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (client[i].montant < client[j].montant)
            {
                new = client[i];
                client[i] = client[j];
                client[j] = new;
            }
        }
    }

     
    system("pause");

}

//=========  Tri Ascendent Par reference =============

void ascendentReferencedFunc()
{

   int i;
   float amount;

    printf("\n> Enter le montant referant\n--> ");
    scanf("%f",&amount);

    ascendentFunc();

     for ( i = 0; i < total; i++)
     {
         if (client[i].montant >= amount)
         {
             displaySingleAccount(i);
         }
         
         
     }
     

   system("pause");
    
}

//=========  Tri descendent Par reference =============

void descendentReferencedFunc()
{

   int i;
   float amount;

    printf("\n> Enter le montant referant\n--> ");
    scanf("%f",&amount);

    descendentFunc();

     for ( i = 0; i < total; i++)
     {
         if (client[i].montant >= amount)
         {
             displaySingleAccount(i);
         }
         
         
     }
     

   system("pause");


}

//================  RECHERCHE PAR CIN ============================

void searchByCin()
{
    int i,index, found = 0;
    char compare[5];

    do
    {
        /* code */

        printf("\nEnter CIN du Client :\n");
        scanf("%s", &compare);

        for (i = 0; i < total; i++)
        {
            if (strcmp(client[i].CIN, compare) == 0)
            {
                index = i;
                found = 1;
                break;
            }
        }
    } while (found == 0);

    displaySingleAccount(index);
}

//=================  Les Fideles ==========================================

void fidelityFunc()
{
    int i;

    descendentFunc();

    printf("\n--- Nos Clients fideles ---\n");
    printf("\n> Affichage apres l ajout de 1,3 aux montants de chacun des 3 premiers \n ");

    for ( i = 0; i < 3; i++)
    {
        client[i].montant += (client[i].montant * 1.3) / 100;
        displaySingleAccount(i);
        system("pause");
    }
    

}

//===========  CALCULE DE LA MOYENNE ===================

void moyenneMontants()
{
  int i;
  float moyenne = 0;

  printf("\n\n--- Affichage de la moyenne ---\n\n");

  for ( i = 0; i < total; i++)
  {
      moyenne += client[i].montant;
  }

  printf(">La moyenne des montants des comptes :\n--> %f",moyenne / total);
  
}

//==========  CHECK WETHER A CLIENT EXISTS OR NOT =========

int checkCIN(char *alpha)
{
    int i;
    for ( i = 0; i < total; i++)
    {
        if (strcmp(alpha,client[i].CIN) == 0)
        {
            return i;
        }else printf("\n> CIN ne correspond a aucun de nos clients !");
        
    }
    

}


void transaction()
{
    int i,index1,index2, success = 0;
    float amount;
    char compare1[5] , compare2[5];

    printf("\n\t--- Processus de Transaction ---\n");

    printf("> Enter CIN Emetteur :\n");
    printf("--> ");
    scanf("%s",&compare1);

    index1 = checkCIN(compare1);

    displaySingleAccount(index1);

    system("pause");

    printf("\n> Enter CIN Recepteur :\n");
    printf("--> ");
    scanf("%s",&compare2);
    
    index2 = checkCIN(compare2);

    displaySingleAccount(index2);

    system("pause");
retry:
    printf("\n> Entrer le montant a envoyer : \n--> ");
    scanf("%f",&amount);

if (amount <= client[index1].montant)
{
    client[index1].montant -= amount;

    client[index2].montant += amount;

    printf("\n> Transaction faite avec succes !");

    displaySingleAccount(index1);
    displaySingleAccount(index2);
} else{
         printf("> Solde insuffisant ! ");
         goto retry;
       } 

    

    
    


}