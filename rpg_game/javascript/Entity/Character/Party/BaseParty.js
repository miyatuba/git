class BaseParty
{
    constructor(is_playable)
    {
        this.is_playable = is_playable;
    }

    isPlayable()
    {
        return this.is_playable;
    }
}


/*BaseParty = function (isPlayable)
{
    this.Playable = isPlayable;

}

BaseParty.Playable;

BaseParty.prototype.isPlayable = function () {
    return this.Playable;
}*/