#include "Includes/Models/Entity.hpp"


namespace CardGame{
class TriggerManager{
   void OnStartTurnTrigger(Entity* sender);

    void OnEndTurnTrigger(Entity* sender);

    void OnAddCardTrigger(Entity* sender);

    void OnDrawCardTrigger(Entity* sender);

    void OnAfterDrawCardTrigger(Entity* sender);

    void OnPlayCardTrigger(Entity* sender);

    void OnAfterPlayCardTrigger(Entity* sender);

    void OnPlayMinionTrigger(Entity* sender);

    void OnAfterPlayMinionTrigger(Entity* sender);

    void OnCastSpellTrigger(Entity* sender);

    void OnAfterCastTrigger(Entity* sender);

    void OnSecretRevealedTrigger(Entity* sender);

    void OnZoneTrigger(Entity* sender);

    void OnGiveHealTrigger(Entity* sender);

    void OnTakeHealTrigger(Entity* sender);

    void OnAttackTrigger(Entity* sender);

    void OnAfterAttackTrigger(Entity* sender);

    void OnSummonTrigger(Entity* sender);

    void OnAfterSummonTrigger(Entity* sender);

    void OnDealDamageTrigger(Entity* sender);

    void OnTakeDamageTrigger(Entity* sender);

    void OnTargetTrigger(Entity* sender);

    void OnDiscardTrigger(Entity* sender);

    void OnDeathTrigger(Entity* sender);

    void OnInspireTrigger(Entity* sender);

    void OnEquipWeaponTrigger(Entity* sender);

    void OnShuffleIntoDeckTrigger(Entity* sender);

    void OnManaCrystalTrigger(Entity* sender);
};
} // namespace CardGam
