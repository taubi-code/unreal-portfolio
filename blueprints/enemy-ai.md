# Enemy AI — Documentation Blueprint

## Objectif
Créer un ennemi qui patrouille entre des points, détecte le joueur visuellement, l'attaque, et retourne en patrouille s'il le perd de vue.

## Architecture

```
BP_EnemyPatrol
├── Components
│   ├── SkeletalMesh (modèle 3D)
│   ├── CapsuleComponent (collision physique)
│   ├── AIPerceptionComponent
│   │   └── AISense_Sight (cône de vision : 45°, 800cm)
│   └── WidgetComponent (barre de vie au-dessus)
├── Variables
│   ├── PatrolPoints (Array of Actor)
│   ├── CurrentPatrolIndex (int)
│   ├── Health (float, défaut: 100)
│   └── AttackDamage (float, défaut: 10)
└── Functions
    ├── TakeDamage (override)
    ├── Die ()
    └── UpdateHealthBar ()
```

## Behavior Tree

```
BT_EnemyPatrol
└── Root
    └── Selector
        ├── [Attaque] Sequence
        │   ├── Check BB: IsAttacking == true
        │   ├── BTTask_RotateToFaceTarget
        │   └── BTTask_Attack (play anim + apply damage)
        ├── [Poursuite] Sequence
        │   ├── Check BB: PlayerSeen == true
        │   └── BTTask_MoveToActor (target: Player)
        └── [Patrouille] Sequence
            ├── BTTask_GetNextPatrolPoint
            └── BTTask_MoveToLocation
```

## Blackboard Keys

| Clé | Type | Description |
|---|---|---|
| `PlayerActor` | Object | Référence au joueur détecté |
| `PlayerSeen` | Bool | Joueur dans le cône de vision |
| `IsAttacking` | Bool | Ennemi en train d'attaquer |
| `LastKnownLocation` | Vector | Dernière position connue du joueur |
| `PatrolTarget` | Vector | Prochain point de patrouille |

## Leçon principale
Découverte de la séparation **Controller / Pawn** dans l'IA : le `AIController` contient la logique de décision, le `Pawn` contient uniquement le corps physique. Principe identique à l'architecture MVC.
