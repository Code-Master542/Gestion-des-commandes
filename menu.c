void DisplayMenu()
{
     printf("\n--- Menu Gestion des Commandes ---\n");
     printf("1. Ajouter une commande\n");
     printf("2. Annuler une commande\n");
     printf("3. Rechercher une commande\n");
     printf("4. Afficher l'historique des commandes\n");
     printf("5. Afficher les commandes en attente\n");
     printf("6. Quitter\n\n");
}

int main()
{
    FileCommande file;
    initFile(&file);

    int choix, id;
    char client[50], description[100], statut[20], date[20];

    do
    {
        DisplayMenu();

        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
            case 1:
                printf("Entrez l'ID de la commande : ");
                scanf("%d", &id);
                printf("Nom du client : ");
                scanf(" %[^\n]", client);
                printf("Description : ");
                scanf(" %[^\n]", description);
                printf("Statut (ex. En attente) : ");
                scanf(" %[^\n]", statut);
                printf("Date : ");
                scanf(" %[^\n]", date);
                ajouterCommande(&file, id, client, description, statut, date);
                break;

            case 2:
                annulerCommande(&file);
                break;

            case 3:
                printf("Entrez l'ID de la commande a rechercher : ");
                scanf("%d", &id);

                Commande* commandeTrouvee = rechercherCommande(&file, id);

                if (commandeTrouvee)
                {
                    printf("Commande trouvee : ID: %d | Client: %s | Description: %s | Statut: %s | Date: %s\n",
                           commandeTrouvee->id, commandeTrouvee->client, commandeTrouvee->description,
                           commandeTrouvee->statut, commandeTrouvee->date);
                }
                else
                {
                    printf("Commande non trouvee.\n");
                }

                break;

            case 4:
                afficherHistorique(&file);
                break;

            case 5:
                afficherCommandesEnAttente(&file);
                break;
            default:
                printf("Choix invalide. Reessayez.\n");
        }

    } while (choix != 6);

    return 0;
}
