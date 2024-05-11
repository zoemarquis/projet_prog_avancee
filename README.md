# Projet : Programmation Avancée
_Charlotte Kruzic & Zoé Marquis_

## Jeu du Casse-briques
Ce projet implémente un jeu du casse-briques classique avec plusieurs types de briques, des bonus et des malus.

---
## Briques
Le jeu comprend différents types de briques, chacune ayant une force différente :

- Brique verte : force 1
- Brique jaune : force 2
- Brique orange : force 3
- Brique rouge : force 4
- Brique violette : force 5

Dans cette version du jeu, nous avons ajouté des briques Bonus/Malus. Ces briques spéciales sont masquées derrière une image, ce qui signifie que vous ne pouvez pas savoir à l'avance quels types de bonus <img src="img/etoile.png" width="30" height="30">
 ou de malus <img src="img/goomba.png" width="30" height="30">
 se cachent derrière elles. Contrairement aux briques normales, ces briques n'ont pas besoin d'être cassées pour remporter la partie.

Il esite aussi des briques indestructibles pour complexifier certaines zone d'accès, elles n'ont pas besoin d'etre détruites pour remporter la partie.

### Bonus
- Décélérateur de la balle : Ralentit la vitesse de la balle
- Agrandissement de la taille de la raquette
  
### Malus 
- Accélérateur de la balle
- Réduction de la taille de la raquette 
  
### Briques Indestructibles
En plus des briques cassables, il existe des briques indestructibles qui ajoutent de la complexité d'accès à certaines zones du jeu. Ces briques ne peuvent pas être détruites et ne contribuent pas à la victoire du joueur.
<img src="img/wall.png" width="30" height="30">
  
--- 
## Bonus et Malus
Les bonus et les malus tombent du ciel, offrant une variété d'effets différents pour pimenter le jeu. Voici les différents types de bonus et de malus disponibles :

### Bonus
- Gris : Décélérateur de la balle - Ralentit la vitesse de la balle.
- Bleu Foncé : Accélérateur de la balle - Augmente la vitesse de la balle.
- Rose : Multiballe - Génère 2 nouvelles balles pour des actions plus dynamiques.

### Malus 
- Vert Foncé : Agrandissement de la taille de la raquette - Augmente la taille de la raquette du joueur.
- Rouge Foncé : Réduction de la taille de la raquette - Diminue la taille de la raquette du joueur.

---
## Notions du cours utilisés / respectées 
- CRTP : SpecialBrick est templatisé à l'aide des classes dont il hérite : BonusBrick et MalusBrick
- polymophisme / héritage (ajouter image schéma héritage)

<img src="diagramme.png">


---
## Répartition des tâches
- Charlotte
- Zoé

---
todo
- patron de conception singleton pour les couleurs 
- simplifier les include / foward declaration
- écrire ce qu'on a implémenté / pas implémenté
- triangles 
- hexagones
- render brick identique à render cell
- ball : attributs inutiles
- pointeur : trasnformer les texture * ...
- const cohérent
- réf, ptr, ...
