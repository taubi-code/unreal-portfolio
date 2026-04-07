# Niveau 01 — Exploration

## Description
Premier niveau jouable : terrain ouvert avec collectibles, obstacles et système de score.

## Mécaniques implémentées
- Déplacement Third Person (marche, sprint, saut)
- 15 collectibles répartis sur la carte (pièces)
- Zone de danger (lave) avec perte de vie
- Timer : compléter la carte en moins de 3 minutes
- Écran de fin (victoire / défaite)

## Blueprints impliqués
- `BP_ThirdPersonCharacter` : mouvement + stamina
- `BP_Collectible` : overlap → score + son + destruction
- `BP_DamageZone` : dégâts continus au contact
- `BP_GameMode_Level01` : gestion timer + conditions de victoire
- `WBP_HUD_Level01` : affichage score, vie, timer

## Concepts clés
- `OnComponentBeginOverlap` pour les collectibles
- `SetTimer by Function Name` pour le compte à rebours
- `Apply Damage` + `Event AnyDamage` pour les dégâts
- Spawn/Destroy d'Actors en runtime

## Captures
> *voir `docs/screenshots/level01-*.png`*
