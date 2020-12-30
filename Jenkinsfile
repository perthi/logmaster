


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
						sh   './scripts/host/compile.sh clean'
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
	 emailext (
      subject: "STARTED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]'",
      body: """<p>STARTED: Job '${env.JOB_NAME} [${env.BUILD_NUMBER}]':</p>
        <p>Check console output at &QUOT;<a href='${env.BUILD_URL}'>${env.JOB_NAME} [${env.BUILD_NUMBER}]</a>&QUOT;</p>""",
      recipientProviders: [[$class: 'DevelopersRecipientProvider']]
    )

}

