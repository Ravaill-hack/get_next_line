L'objectif est ici de creer une fonction qui permettra de lire un fichier texte ligne par ligne, avec un pas de lecture donne (BUFFER_SIZE).

Nous faisons appel a 4 variables :
- char *  buffer
- char *  rawline
- char *  line
- static char *  toomuchread

buffer :
C'est dans cette variable que l'on va stocker chaque echantillon de lecture. On appelle "echantillon" la portion de caracteres qui va etre
lue a chaque appel de la fonction systeme read. L'idee est donc d'allouer un espace memoire de taille ((BUFFER_SIZE + 1) * sizeof(char)) bytes
En effet, si on lit caracteres 2 par 2 (BUFFER_SIZE = 2), il faudra etre capable a chaque lecture de stocker 2 caracteres dans buffer ( + le
caractere nul).

rawline :
Cette variable est creee par concatenations successives de chaque echantillon (ou buffer), tant qu'on n'a pas atteint de retour a la ligne.
Ainsi, pour le fichier texte suivant lu avec un BUFFER_SIZE = 8 :

  Il parait que\n
  les chats sont gris\n
  tant pis

rawline va etre issue de la concatenation des 2 premiers echantillons de taille 8 : "Il parai\0" et "t que\nle\0". A ce stade rawline vaut donc
"Il parait que\nle\0" . Il se compose donc de la ligne 1 en entier + une partie de la ligne 2. 

Il est donc necessaire de tronquer rawline pour ne garder que les caracteres avant le retour a la ligne (cette sous chaine sera appelee "line", mais
il faut egalement veiller a conserver la deuxieme partie de rawline, qui contient les premiers caracteres de la ligne d'apres. En effet, le fonction
"read" n'est pas capable de revenir en arriere ; si elle a depasse le debut de la ligne d'apres elle reprendra la ou elle s'est arretee. En l'absence
de traitement particulier, la deuxieme rawline lue serait donc "s chats sont gris\ntant p" alors qu'on aimerait avoir "les chats sont gris\ntant p".
On definit alors une derniere variable : "toomuchread" qui va stocker les premiers caracteres lus de la ligne d'apres. On a donc :

line :
Une sous chaine extraite de rawline, allant du debut de la chaine jusqu'au retour a la ligne

toomuchread :
Une sous chaine extraite de rawline, allant du caractere suivant le retour a la ligne jusqu'a la fin de la chaine


En resume, chaque rawline est creee par les concatenations successives de toomuchread et de tous les buffers lus sur la ligne (avec toomuchread
initialise a NULL pour ne pas perturber la lecturede la premiere ligne)

  
