
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
	}

}