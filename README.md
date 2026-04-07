# 🎮 Unreal Engine 5 — Portfolio Personnel

> Projet réalisé durant mon année de consolidation (2025-2026) pour explorer le développement de jeux vidéo et l'architecture logicielle via Unreal Engine 5.

---

## 🎯 Objectifs du projet

Ce portfolio documente mon apprentissage autonome d'Unreal Engine 5, en lien avec mon intérêt pour :
- La **programmation orientée événement** (Blueprints / C++)
- L'**architecture logicielle** des moteurs de jeux
- Le **rendu 3D et la gestion de ressources** (assets, mémoire, GPU)
- La **logique de gameplay** (game loop, états, collisions)

---

## 📁 Contenu du projet

```
unreal-portfolio/
├── README.md
├── levels/                   # Description des niveaux créés
│   ├── level-01-exploration.md
│   └── level-02-platformer.md
├── blueprints/               # Documentation des Blueprints
│   ├── player-controller.md
│   ├── enemy-ai.md
│   └── inventory-system.md
├── docs/
│   ├── architecture.md       # Architecture technique du projet
│   ├── lessons-learned.md    # Ce que j'ai appris
│   └── screenshots/          # Captures d'écran
└── journal.md               # Journal de progression semaine par semaine
```

---

## 🕹️ Niveaux réalisés

### Niveau 1 — Exploration (Starter)
- Terrain généré avec **Landscape Tool**
- Éclairage dynamique (Lumen)
- Déplacement du personnage via **Character Movement Component**
- Collectibles avec système de score

### Niveau 2 — Plateforme
- Plateformes mobiles pilotées par **Timeline Blueprint**
- Système de vie et game over
- Interface HUD minimale (UMG Widgets)
- Caméra dynamique (Spring Arm + Camera Boom)

---

## 🔵 Blueprints documentés

### Player Controller
Gestion des inputs clavier/souris, saut, sprint, interaction avec objets.  
Concepts : `Event Tick`, `Input Action`, `Cast To`, variables d'état.

### Enemy AI
Patrouille basique avec **Behavior Tree** + **Blackboard**.  
Détection du joueur via `Perception Component` (vision cone).

### Inventory System
Tableau de structs, ajout/suppression d'items, sauvegarde en `SaveGame`.

---

## 🧠 Ce que j'ai appris

| Domaine | Compétences acquises |
|---|---|
| Architecture | Séparation logique gameplay / rendu / UI |
| Programmation | Blueprints → portage en C++ (classes de base) |
| Algorithmes | Pathfinding A* (NavMesh), gestion d'états (FSM) |
| Systèmes | Gestion mémoire, streaming de niveaux, LOD |
| Mathématiques | Vecteurs 3D, quaternions, interpolation (Lerp) |

---

## 🔧 Environnement technique

- **Moteur** : Unreal Engine 5.3
- **Langage** : Blueprints (Visual Scripting) + C++ (introduction)
- **OS** : Windows 11
- **Outils** : Git LFS pour les assets binaires, Rider pour le C++

---

## 📈 Progression

```
Semaine 1-2  : Interface UE5, création de terrain, lumières
Semaine 3-4  : Blueprints de base, mouvement du personnage
Semaine 5-6  : Physique, collisions, triggers
Semaine 7-8  : IA ennemis (Behavior Tree)
Semaine 9-10 : HUD, menus, système de sauvegarde
Semaine 11+  : Portage C++ des Blueprints critiques
```

---

## 🔗 Liens

- [Mon GitHub](https://github.com/taubi-code)
- [Documentation Unreal Engine 5](https://docs.unrealengine.com/5.0/en-US/)
- [Mon stage — intuitivesoft.net](https://intuitivesoft.net)

---

## 📌 Pourquoi ce projet ?

L'étude d'un moteur de jeu est une façon concrète d'explorer des concepts fondamentaux de l'informatique :
- **Architecture logicielle** : comment un moteur découple rendu, physique, gameplay
- **Algorithmique** : pathfinding, détection de collisions, animation par état
- **Systèmes** : gestion mémoire, temps réel, optimisation

Ce projet fait partie de mon portfolio de candidature pour des études en Licence Informatique.
