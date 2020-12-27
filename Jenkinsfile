
pipeline
{
    agent any

	stages
	{	
		stage("Build compiler docker image")
		{
				dir("docker-cross2")
				{
					sh './create-image.sh'
				}
		}
	}

}