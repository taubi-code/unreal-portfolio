# Journal de progression — Unreal Engine 5

## Semaine 1 (oct. 2025) — Prise en main
- Installation UE5.3, découverte de l'interface
- Création d'un projet vide Third Person Template
- Exploration du Content Browser, World Outliner
- **Difficulté** : comprendre la différence Actor / Component / Scene

## Semaine 2 — Terrain et éclairage
- Landscape Tool : création d'un terrain de 2km²
- Peinture de textures (couche herbe / roche / neige)
- Lumen : éclairage dynamique global, test avec soleil mobile
- **Découverte** : le coût GPU de Lumen → intro à l'optimisation

## Semaine 3-4 — Blueprints : bases
- Variables, fonctions, macros dans un Blueprint
- Mouvement du personnage : override de `CharacterMovement`
- Système de sprint (Shift) avec stamina limitée
- **Concept clé appris** : Event-driven vs polling (Event Tick à éviter)

## Semaine 5-6 — Physique et collisions
- Composant `Box Collision`, `On Component Begin Overlap`
- Plateformes mobiles : `Timeline` + `Lerp` pour interpolation
- Portes automatiques, déclencheurs de zone
- **Lien avec cours** : vecteurs 3D, interpolation linéaire

## Semaine 7-8 — Intelligence artificielle
- Navigation : NavMesh baking pour le pathfinding
- Behavior Tree + Blackboard : patrouille / alerte / attaque
- `AIPerceptionComponent` : détection visuelle du joueur
- **Concept clé** : FSM (Finite State Machine) appliqué à l'IA

## Semaine 9-10 — Interface et sauvegarde
- UMG Widgets : HUD (vie, score, minimap)
- Menu principal et pause
- `SaveGame` : sérialisation de la progression
- **Difficulté** : binding entre UI et gameplay (architecture MVC)

## Semaine 11-12 — Introduction C++
- Conversion d'un Blueprint simple en classe C++
- `AActor`, `UActorComponent`, `UPROPERTY`, `UFUNCTION`
- Compilation avec Rider for Unreal
- **Observation** : Blueprints = prototype rapide, C++ = performance

## Bilan
- ~120 heures de travail autonome
- 2 niveaux jouables et documentés
- Compréhension de l'architecture d'un moteur de jeu professionnel
- Bases solides pour approfondir en contexte académique
