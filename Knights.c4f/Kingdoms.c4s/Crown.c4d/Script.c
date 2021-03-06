#strict

protected func Initialize()
  {
  // Blinkaktivit�t setzen
  SetAction("Glitter0");
  return(1);
  }

// Auftreffsound
protected func Hit() { return(Sound("Crystal*")); }

// Aktivit�t
protected func Glittering()
  {
  // Mana-Regeneration
  if (!Random(20))
    if (Contained())
      if (DoMagicEnergy(1, Contained())) CreateParticle("PxSpark",0,0,0,0,10,RGB(0,0,255));
  // Effekt
  return(SetAction(Format("Glitter%d", Random(5))));
  }

// Einsammelbar?
protected func RejectEntrance(pNewContainer)
  {
  // Nur aus dem K�nig heraus (in Container ablegen), und in den K�nig hinein (aufsammeln)
  if (GetID(Contained()) == KING) return();
  if (GetID(pNewContainer) == KING) return();
  // Ansonsten ablehnen
  return(1);
  }
