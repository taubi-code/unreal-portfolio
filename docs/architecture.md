# Architecture technique — Unreal Engine 5 Portfolio

## Vue d'ensemble

```
┌─────────────────────────────────────────────┐
│               Game Instance                 │  ← persistant toute la session
├─────────────┬───────────────────────────────┤
│  Game Mode  │      Game State               │  ← règles + état global
├─────────────┴───────────────────────────────┤
│         Player Controller                   │  ← inputs, caméra
│         ↕                                   │
│         Pawn / Character                    │  ← corps physique du joueur
│           ├── Mesh (SkeletalMesh)           │
│           ├── CapsuleComponent (collision)  │
│           ├── CharacterMovement             │
│           └── SpringArm + Camera           │
├─────────────────────────────────────────────┤
│         HUD / UMG Widgets                   │  ← interface utilisateur
├─────────────────────────────────────────────┤
│         AI Controller                       │
│           ├── Behavior Tree                 │
│           ├── Blackboard                    │
│           └── AIPerception                  │
└─────────────────────────────────────────────┘
```

## Patterns utilisés

### Event-Driven Architecture
UE5 repose sur un système d'événements : les objets ne se « polident » pas mutuellement, ils émettent et reçoivent des événements (`Delegates`, `Dispatchers`).

```
Joueur touche collectible
  → OnComponentBeginOverlap (event)
    → Cast To BP_Collectible
      → Collect() appelé
        → Dispatcher → HUD mis à jour
```

### Component Pattern
Chaque fonctionnalité est un composant attaché à un Actor, pas une classe monolithique. Réutilisabilité maximale.

### State Machine (FSM) pour l'IA
```
[Patrouille] --voit joueur--> [Alerte] --joueur proche--> [Attaque]
     ↑                                                        |
     └──────────────── joueur disparu ───────────────────────┘
```

## Leçons d'architecture

| Principe | Application dans UE5 |
|---|---|
| Séparation des responsabilités | Controller ≠ Pawn ≠ HUD |
| Couplage faible | Event Dispatchers plutôt qu'appels directs |
| Réutilisabilité | Components indépendants du contexte |
| Performance | Éviter Event Tick, préférer les events |
