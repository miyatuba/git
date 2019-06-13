class BaseParty
{
    constructor(is_playable,)
    {
        this.is_playable = is_playable;
        this.party_target_position_number = 1;
        this.enemy_target_position_number = 1;
    }

    isPlayable()
    {
        return this.is_playable;
    }

    setPartyTargetPositionNumber(position_number)
    {
        this.party_target_position_number = position_number;
    }

    setEnemyTargetPositionNumber(position_number)
    {
        this.enemy_target_position_number = position_number;
    }

    get
}


/*BaseParty = function (isPlayable)
{
    this.Playable = isPlayable;

}

BaseParty.Playable;

BaseParty.prototype.isPlayable = function () {
    return this.Playable;
}*/