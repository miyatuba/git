using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Difficult : MonoBehaviour
{
    private int difficult_id;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void setId(int difficult_id)
    {
        this.difficult_id = difficult_id;
    }

    public int getId()
    {
        return this.difficult_id;
    }
}
