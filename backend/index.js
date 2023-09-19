const express=require("express");
const cors=require("cors");
const corsOptions ={
   origin:'*', 
   credentials:true,            //access-control-allow-credentials:true
   optionSuccessStatus:200,
}


const app=express();
const data=require("./server.js")
app.use(express.json())
app.use(cors(corsOptions))
app.get("/vans",async(req,res)=>{
    try{
      
    return res.status(200).send(data);
    }
    catch(e){
        return res.status(404).send("erroe");
    }
})
app.get("/vans/:id",async(req,res)=>{
    try{
      
    return res.status(200).send(data[req.params.id-1]);
    }
    catch(e){
        return res.status(404).send("erroe");
    }
})
app.get("/host/vans",async(req,res)=>{
    try{
      
    return res.status(200).send(data);
    }
    catch(e){
        return res.status(404).send("error");
    }
})

app.get("/host/vans/:id",async (req,res)=>{
  
    try{
       
          
        return res.status(200).send( data[req.params.id-1]);
        }
        catch(e){
            return res.status(404).send("erroe");
        }
})

app.post("/login",async (req,res)=>{
   console.log(req.url)
    try{
        console.log(req.body)
        const token=JSON.stringify(req.body);
        
        return res.send({
            user:"found",
            Token:token
        }).status(200);

    }
    catch(e){
       return  res.send(e).status(400)

    }
})
app.listen(4000,(e)=>{ 
    console.log("running")
})