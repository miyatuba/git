using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HeroineMask : MonoBehaviour
{
    private int heroine_id;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setId(int heroine_id)
    {
        this.heroine_id = heroine_id;
    }

    public int getId()
    {
        return this.heroine_id;
    }
}
