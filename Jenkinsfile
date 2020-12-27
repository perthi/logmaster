
pipeline
{
    agent none
    stages
    {
		stage("Build compiler docker image")
		{
			agent
			{
				label "linuxdocker"
			}
			steps
			{
				dir("docker-cross")
				{
					sh './create-image.sh'
				}
			}
		}
	}
}