using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SelectTargetItem : MonoBehaviour
{//Itemはここでは項目の意味、道具ではない
    private int target_id;

    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setId(int target_id)
    {
        this.target_id = target_id;
    }

    public int getId()
    {
        return this.target_id;
    }

}
