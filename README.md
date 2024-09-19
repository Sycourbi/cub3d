# cub3d

![C Language](https://img.shields.io/badge/language-C-blue)
![Game Engine](https://img.shields.io/badge/game%20engine-3D-yellowgreen)
![Graphics](https://img.shields.io/badge/graphics-2D%20%2F%203D-orange)
![Documentation](https://img.shields.io/badge/docs-available-brightgreen)
![Code Quality](https://img.shields.io/badge/code%20quality-A-brightgreen)
![License](https://img.shields.io/badge/license-MIT-blue)
![Labyrinthe](https://img.shields.io/badge/labyrinthe-yes-green)


# Description

**cub3d** est un projet de développement d'un moteur de jeu 3D en utilisant la technique du raycasting. Inspiré par des jeux classiques tels que **Wolfenstein 3D**, ce projet permet de visualiser une carte 2D sous forme de monde 3D interactif. L'objectif est de créer un rendu 3D basé sur une carte en 2D, en utilisant les concepts de raycasting et de projection.

# Objectif

L'objectif de **cub3d** est de fournir une implémentation fonctionnelle d'un moteur de jeu 3D simple, en se concentrant sur les aspects suivants :
- Rendu 3D basé sur une carte en 2D.
- Gestion des murs, des textures et de la perspective.
- Implémentation de la caméra et du mouvement du joueur.


# Services

- **Compilateur** : GCC .
- **Bibliothèques** : Utilisation de la bibliothèque graphique MiniLibX pour le rendu.

# Installation

Pour cloner et compiler le projet, suivez les étapes ci-dessous :

1. Clonez le dépôt :

   ```bash
   git clone https://github.com/votre-utilisateur/cub3d.git
   cd cub3d
   make
   ./cub3d maps/map1.cub

# Utilisation
Pour utiliser cub3d, lancez le programme en lui fournissant un fichier de carte .cub. Le fichier de carte décrit la disposition du niveau, les textures des murs, le sol et le plafond.
