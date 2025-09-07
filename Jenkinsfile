

def sendMail() 
{
     mail bcc: '', 
     body: "<b>Example</b><br>Project: ${env.JOB_NAME} <br>Build Number: ${env.BUILD_NUMBER} <br> URL: <a href = ${env.BUILD_URL}>${env.BUILD_URL}</a>", 
     cc: '', 
     charset: 'UTF-8', 
     from: 'pth@embc.no', 
     mimeType: 'text/html', 
     replyTo:   'noreply@logmaster-jenkins', 
     subject:   "${currentBuild.result} CI: Project name -> ${env.JOB_NAME}", 
     to: "pth@embc.no";      
}



pipeline
{
    agent any

    stages
    {
        stage("Build")
        {    
        
            stages
            {    
                stage("Create docker image")
                {
                    steps
                    {
                        dir("docker-cross")
                        {    
                            sh 'whoami'
                            sh './create-image.sh'
                        }
                    }
                }
                stage("X86-compile")
                {                            
                    steps
                    {
                    //    sh   './scripts/host/compile.sh clean'
                        sh   './scripts/host/compile.sh x86'
                    }
                }
                stage("ARM-compile")
                {                            
                    steps
                    {
                        sh   './scripts/host/compile.sh arm'
                    }
                }
            }
        }
        stage("Running tests")
        {
            stages
            {
            stage("X86-unittests")
            {                            
                steps
                {
                    sh './scripts/host/run-tests.sh x86'
                }
            }
            }    

        }

    }
     post {  
         always {  
             echo 'This will always run'
             step([$class: 'CordellWalkerRecorder'])
             sendMail();
		}  
         success {
			 sendMail(); 
             echo 'This will run only if successful'  
         }  
         failure {
             sendMail();   
         }  
         unstable {  
             echo 'This will run only if the run was marked as unstable'  
         }  
         changed {  
             sendMail();
			 echo 'This will run only if the state of the Pipeline has changed'  
             echo 'For example, if the Pipeline was previously failing but is now successful'  
         }  
 }  


}



