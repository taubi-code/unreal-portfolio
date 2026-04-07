# Niveau 02 — Plateforme

## Description
Niveau de plateforme avec ennemis patrouilleurs, plateformes mobiles et boss simple.

## Mécaniques implémentées
- Sauts précis sur plateformes mobiles (Timeline Lerp)
- 3 ennemis patrouilleurs avec IA Behavior Tree
- Système de vie (3 cœurs) + animation de dégâts
- Checkpoint (sauvegarde position si mort)
- Boss final : phases d'attaque selon % de vie

## Blueprints impliqués
- `BP_MovingPlatform` : Timeline + Lerp entre 2 points
- `BP_EnemyPatrol` : AI Controller + Behavior Tree
- `BP_Checkpoint` : sauvegarde de la position de spawn
- `BP_Boss` : FSM à 3 phases (lente / rapide / rage)
- `WBP_HUD_Level02` : cœurs, boss healthbar

## IA — Behavior Tree structure
```
Root
└── Selector
    ├── Sequence [mode Attaque]
    │   ├── Blackboard: PlayerInRange == true
    │   └── BTTask_MoveToPlayer
    ├── Sequence [mode Alerte]
    │   ├── Blackboard: PlayerSeen == true
    │   └── BTTask_MoveToLastKnownLocation
    └── BTTask_Patrol   [mode Patrouille]
```

## Difficulté rencontrée
Synchronisation des plateformes mobiles avec le personnage dessus : utilisation de `AttachToComponent` temporaire pour éviter le glissement.

## Concepts clés
- Behavior Tree + Blackboard Keys
- `EQS` (Environment Query System) pour choisir la position d'attaque du boss
- `SaveGame` pour les checkpoints
