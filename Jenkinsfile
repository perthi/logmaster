


pipeline
{
    agent any

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
				sh 'pwd'
				sh   './scripts/host/compile.sh clean'
				sh   './scripts/host/compile.sh x86'
			}
		}
		stage("ARM")
		{							
			steps
			{
				sh 'pwd'
				sh   './scripts/host/compile.sh arm'
			}
		}
	}

}

