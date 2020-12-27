


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
						sh   './make  distclean'
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

}

