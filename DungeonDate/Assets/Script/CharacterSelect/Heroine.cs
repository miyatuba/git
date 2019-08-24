using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Heroine : MonoBehaviour
{
    private int heroine_id;

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
