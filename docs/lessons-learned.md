# Ce que j'ai appris — Bilan

## Concepts informatiques découverts via UE5

### Algorithmique
- **A* / NavMesh** : pathfinding pour l'IA ennemie. Comprendre le coût heuristique, les nœuds ouverts/fermés.
- **Interpolation** : `Lerp`, `FInterpTo`, `Timeline` pour animer sans physique rigide.
- **Tri et recherche** : gestion de l'inventaire (tableau de structs, recherche par tag).

### Architecture logicielle
- Pattern **Component** : composition vs héritage pour construire des Actors.
- **Event-driven** : ne pas vérifier à chaque frame, écouter des événements.
- **MVC approché** : séparation Model (GameState), View (HUD), Controller (PlayerController).

### Systèmes bas niveau (entrevus)
- Streaming de niveaux : charger/décharger des zones pour économiser la RAM.
- **LOD (Level of Detail)** : réduire la complexité des meshes en fonction de la distance.
- **Occlusion Culling** : ne pas rendre ce qui n'est pas visible.
- Gestion mémoire : garbage collector d'Unreal, cycles de vie des objets (`BeginPlay`, `EndPlay`).

### Mathématiques appliquées
- **Vecteurs 3D** : déplacement, direction, produit scalaire pour détecter la vision ennemie.
- **Quaternions** : rotations sans gimbal lock (utilisés partout dans UE5).
- **Trigonométrie** : cone de vision de l'IA (`FMath::Acos`, angle entre vecteurs).

### Ce que je veux approfondir en licence
- Implémentation d'un moteur de rendu simplifié (rastérisation, shaders)
- Algorithmique de pathfinding (comparaison A* / Dijkstra / BFS)
- Architecture d'un moteur ECS (Entity Component System)
- Programmation C++ bas niveau des systèmes temps réel
