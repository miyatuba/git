using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CardModel : MonoBehaviour
{
    private int card_id;
    private int value;
    private int mark_id;
    private GameObject card_object;

    public CardModel(Hashtable card_data)
    {
        this.card_id = (int)card_data["card_id"];
        this.value = (int) card_data["value"];
        this.mark_id = (int) card_data["mark_id"];
        this.card_object = (GameObject) card_data["card_object"];
    }

    public int GetCardId()
    {
        return this.card_id;
    }

    public int GetValue()
    {
        return this.value;
    }

    public int GetMarkId()
    {
        return this.mark_id;
    }

    public GameObject GetCardObject()
    {
        return this.card_object;
    }
}
