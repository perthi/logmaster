



pipeline
{
    agent any

	stages
	{
		stage("Build")
		{	
		
			stages
			{	
				stage("Build compiler docker image")
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
				stage("X86")
				{							
					steps
					{
					//	sh   './scripts/host/compile.sh clean'
						sh   './scripts/host/compile.sh x86'
					}
				}
				stage("ARM")
				{							
					steps
					{
						sh   './scripts/host/compile.sh arm'
					}
				}
			}
		}
		stage("Unit tests")
		{
			stages
			{
			stage("X86")
			{							
				steps
				{
					sh './scripts/host/run-tests.sh x86'
				}
			}
			stage("ARM")
			{							
				steps
				{
					sh './scripts/host/run-tests.sh arm'
				}
			}
			}	

		}

	}
	 post {  
         always {  
             echo 'This will always run'  
         }  
         success {  
             echo 'This will run only if successful'  
         }  
         failure {  
             mail bcc: '', 
			 body: "<b>Example</b><br>Project: ${env.JOB_NAME} <br>Build Number: ${env.BUILD_NUMBER} <br> URL de build: ${env.BUILD_URL}", 
			 cc: '', 
			 charset: 'UTF-8', 
			 from: 'pth@embc.no', 
			 mimeType: 'text/html', 
			 replyTo: 'noreply@logmaster-jenkins', 
			 subject:  "${env.RESULT} ERROR CI: Project name -> ${env.JOB_NAME}", 
			 to: "pth@embc.no";  
         }  
         unstable {  
             echo 'This will run only if the run was marked as unstable'  
         }  
         changed {  
             echo 'This will run only if the state of the Pipeline has changed'  
             echo 'For example, if the Pipeline was previously failing but is now successful'  
         }  
     }  


}



